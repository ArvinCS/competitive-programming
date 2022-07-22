#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e3 + 5;

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
};

Fenwick tree;
int a[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	tree.reset();
	
	int prvAns = 0;
	for(int x=n-1;x>=0;x--){
		prvAns += tree.query(a[x]-1);
		tree.update(a[x], 1);
	}
	
	int mn = 1e9, ans = 0;
	for(int x=0;x<n;x++){
		tree.reset();
		tree.update(a[x], 1);
		
		for(int y=x+1;y<n;y++){
			int cost = prvAns;
			
			cost -= tree.query(a[x]-1);
			cost -= (y-x) - tree.query(a[y]);
			cost += (y-x) - tree.query(a[x]);
			cost += tree.query(a[y]-1);
			
			if(cost < mn){
				mn = cost;
				ans = 0;
			}
			if(cost == mn){
				ans++;
			}
			tree.update(a[y], 1);
		}
	}
	
	cout << mn << " " << ans << "\n";
    return 0;
}

