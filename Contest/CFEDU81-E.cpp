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

const int maxN = 2e5 + 5;

struct SegmentTree { // index start from 0 (v)
	ll tree[4*maxN], lazy[4*maxN];
	int n;
	void reset(int n){
		this->n = n;
		
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int p[n];
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	tree.reset(n);
	
	for(int x=n-1;x>=0;x--){
		tree.update(0, 0, n, p[x], n, a[x]);
	}
	
	ll ans = inf_ll;
	for(int x=0;x<n-1;x++){
		tree.update(0, 0, n, p[x], n, -a[x]);
		tree.update(0, 0, n, 0, p[x]-1, a[x]);
		
		ans = min(ans, tree.query(0, 0, n, 0, n));
	}
	
	cout << ans << "\n";
    return 0;
}

