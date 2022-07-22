#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 6e5 + 5;

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	int query(int pos){
		pos++;
		
//		pos = maxN-pos;
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos++;
		
//		pos = maxN-pos;
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
};

Fenwick tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int a[m];
	for(int x=0;x<m;x++){
		cin >> a[x];
		a[x]--;
	}
	
	int mx[n], mn[n];
	for(int x=0;x<n;x++){
		mx[x] = x+1;
		mn[x] = x+1;
	}
	
	tree.reset();
	
	int t[n];
	for(int x=n-1;x>=0;x--){
		t[x] = (n-1-x);
		tree.update(t[x], x+1);
		tree.update(t[x]+1, -(x+1));
	}
	
	for(int x=0;x<m;x++){
		mn[a[x]] = min(mn[a[x]], 1);
		mx[a[x]] = max(mx[a[x]], tree.query(t[a[x]]));
		
		tree.update(t[a[x]]+1, 1);
		t[a[x]] = n+x;
		tree.update(t[a[x]]+1, -1);
	}
	
	for(int x=0;x<n;x++){
		mx[x] = max(mx[x], tree.query(t[x]));
	}
	for(int x=0;x<n;x++){
		cout << mn[x] << " " << mx[x] << "\n";
	}
    return 0;
}

