#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct SegTree { // index start from 0 (v)
	pair<ll, int> tree[4*maxN];
	ll lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+maxN, make_pair(-1e18, -1));
		fill(lazy, lazy+maxN, 0);
	}
	
	void push(int v){
		tree[v*2+1].first += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2].first += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void build(int v, int l, int r, ll a[]){
		if(l > r){
			lazy[v] = 0;
			tree[v] = {-1e18, -1};
			return;
		}
		
		if(l == r){
			tree[v] = {a[l], l};
			lazy[v] = 0;
		} else {
			int m = (l+r) >> 1;
			
			build(2*v+1, l, m, a);
			build(2*v+2, m+1, r, a);
			
			lazy[v] = 0;
			tree[v] = max(tree[2*v+1], tree[2*v+2]);
		}
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v].first += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = max(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	pair<ll, int> query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return {-1e18, -1};
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
} tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x] -= (n-x-1);
		}
		
		tree.build(0, 0, n-1, a);
		
		bool exist[n];
		fill(exist, exist+n, true);
		
		for(int x=0;x<k;x++){
			pair<ll, int> mx = tree.query(0, 0, n-1, 0, n-1);
			
			if(mx.first < 0) break;
			
			exist[mx.second] = false;
//			cout << mx.first << " " << mx.second << " " << mx.first-1e18 << "\n";
			tree.update(0, 0, n-1, mx.second, mx.second, -mx.first-1e18);
		}
		
		int cnt = 0;
		ll ans = 0;
		for(int x=0;x<n;x++){
			if(exist[x]){
				ans += a[x]+(n-x-1)+cnt;
			} else {
				cnt++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}


