#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5;

struct SegmentTree {
	ll tree[4*maxN];
	ll mn[4*maxN], mx[4*maxN], lazy[4*maxN];
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(mn, mn+4*maxN, 1e18);
		fill(mx, mx+4*maxN, -1e18);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int curL, int curR, int v){
		if(lazy[v] > 0){
			int curM = (curL+curR) >> 1;
			
			lazy[2*v+1] = mn[2*v+1] = mx[2*v+1] = lazy[v];
			tree[2*v+1] = (curM-curL+1)*mx[2*v+1];
			
			lazy[2*v+2] = mn[2*v+2] = mx[2*v+2] = lazy[v];
			tree[2*v+2] = (curR-(curM+1)+1)*mx[2*v+2];
			
			lazy[v] = 0;
		}
	}
	
	void build(int v, int l, int r, ll a[]){
		if(l > r) return;
		if(l == r){
			tree[v] = mn[v] = mx[v] = a[l];
			return;
		}
		
		int m = (l+r) >> 1;
		
		build(2*v+1, l, m, a);
		build(2*v+2, m+1, r, a);
		
		tree[v] = tree[2*v+1] + tree[2*v+2];
		mn[v] = min(mn[2*v+1], mn[2*v+2]);
		mx[v] = max(mx[2*v+1], mx[2*v+2]);
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r || curL > curR || mn[v] >= val) return;
		if(curL == l && curR == r && mx[v] <= val){
			tree[v] = (curR-curL+1)*val;
			mx[v] = val;
			mn[v] = val;
			lazy[v] = val;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		push(curL, curR, v);
		
		update(2*v+1, curL, curM, l, min(curM, r), val);
		update(2*v+2, curM+1, curR, max(curM+1, l), r, val);
		
		tree[v] = tree[2*v+1] + tree[2*v+2];
		mn[v] = min(mn[2*v+1], mn[2*v+2]);
		mx[v] = max(mx[2*v+1], mx[2*v+2]);
	}
	
	pair<int, ll> query(int v, int curL, int curR, int l, int r, ll val){
		if(l > r || curL > curR || mn[v] > val) return {0, 0};
		if(curL == l && curR == r && mx[v] <= val && tree[v] <= val){
			return {curR-curL+1, tree[v]};
		}
		
		int curM = (curL+curR) >> 1;
		
		push(curL, curR, v);
		
		pair<int, ll> ql = query(2*v+1, curL, curM, l, min(curM, r), val);
		pair<int, ll> qr = query(2*v+2, curM+1, curR, max(curM+1, l), r, val-ql.second);
		
		return {ql.first+qr.first, ql.second+qr.second};
	}
};
 
SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	tree.reset();
	tree.build(0, 0, n-1, a);
	
	while(q--){
		int t, x;
		ll y;
		cin >> t >> x >> y;
		
		x--;
		if(t == 1){
			tree.update(0, 0, n-1, 0, x, y);
		} else {
			cout << tree.query(0, 0, n-1, x, n-1, y).first << "\n";
		}
	}
    return 0;
}

