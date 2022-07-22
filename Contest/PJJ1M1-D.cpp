#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}	
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans = max(ans, tree[pos]);
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] = max(tree[pos], val);
			pos += pos&(-pos);
		}
	}
};

Fenwick tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;
	}
	
	tree.reset();
	
	for(int x=0;x<n;x++){
		int mx = tree.query(a[x]);
		tree.update(a[x], mx+1);
	}
	
	cout << tree.query(n-1) << "\n";
    return 0;
}

