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

const int maxN = 3e5;

int a[maxN];

struct SegTree { // index start from 0 (v)
	ll tree[4*maxN+5], lazy[4*maxN+5];
	int lazy_lock[4*maxN+5], lock[4*maxN+5];
	
	void reset(){
		fill(tree, tree+4*maxN+5, 0);
		fill(lazy, lazy+4*maxN+5, -1);
		fill(lock, lock+4*maxN+5, 0);
		fill(lazy_lock, lazy_lock+4*maxN+5, -1);
	}
	
	void build(int v, int l, int r){
		if(l > r) return;
		if(l == r){
			tree[v] = a[l];
//			cout << v << " -> " << a[l] << "\n";
			return;
		}
		
		int m = (l+r) >> 1;
		build(2*v+1, l, m);
		build(2*v+2, m+1, r);
		
		tree[v] = tree[2*v+1] + tree[2*v+2];
	}
	
	void push(int v, int l, int m, int r){
		if(lazy[v] != -1){
			tree[v*2+1] = (m-l+1-lock[v*2+1])*lazy[v];
			lazy[v*2+1] = lazy[v];
			
			tree[v*2+2] = (r-m-lock[v*2+2])*lazy[v];
			lazy[v*2+2] = lazy[v];
			
			lazy[v] = -1;
		}
		if(lazy_lock[v] != -1){
			lock[v*2+1] = (m-l+1)*lazy_lock[v];
			lazy_lock[v*2+1] = lazy_lock[v];
			
			lock[v*2+2] = (r-m)*lazy_lock[v];
			lazy_lock[v*2+2] = lazy_lock[v];
			
			lazy_lock[v] = -1;
		}
	}
	
	int queryLock(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return lock[v];
		}
		
		int curM = (curL+curR) >> 1;
		push(v, curL, curM, curR);
		return queryLock(v*2+1, curL, curM, l, min(r, curM)) + queryLock(v*2+2, curM+1, curR, max(l, curM+1), r);
	}
	
	void update(int v, int curL, int curR, int l, int r, int val1, int val2){
		if(l > r) return;
		if(curL == l && r == curR){
			if(val1 != -1){
				tree[v] = (curR-curL+1-lock[v])*val1;
				lazy[v] = val1;
			}
			if(val2 != -1){
				lock[v] = (curR-curL+1)*val2;
				lazy_lock[v] = val2;
			}
		} else {
			int curM = (curL+curR) >> 1;
			
			push(v, curL, curM, curR);
			update(v*2+1, curL, curM, l, min(r, curM), val1, val2);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val1, val2);
			
			tree[v] = tree[v*2+1] + tree[v*2+2];
			lock[v] = lock[v*2+1] + lock[v*2+2];
		}
	}
	
	void updateSum(int v, int curL, int curR, int l, int r, ll val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] = (curR-curL+1-queryLock(0, 0, maxN, l, r))*val;
			lazy[v] = val;
		} else {
			if(curL == curR) return;
			
			int curM = (curL+curR)/2;
			
			push(v, curL, curM, curR);
			updateSum(v*2+1, curL, curM, l, min(r, curM), val);
			updateSum(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = tree[v*2+1] + tree[v*2+2];
		}
	}
	
	ll querySum(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;
		push(v, curL, curM, curR);
		return querySum(v*2+1, curL, curM, l, min(r, curM)) + querySum(v*2+2, curM+1, curR, max(l, curM+1), r);
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	fill(a, a+maxN, 0);
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	tree.reset();
	tree.build(0, 0, maxN);
	
	int idx = n;
	while(q--){
		char t;
		cin >> t;
		
		if(t == 'F'){
			int l, r, val;
			cin >> l >> r >> val;
			
			l--; r--;
//			cout << tree.queryLock(0, 0, maxN, l, r) << "\n";
			tree.updateSum(0, 0, maxN, l, r, val);
		} else if(t == 'I'){
			int val;
			cin >> val;
			
			tree.updateSum(0, 0, maxN, idx, idx, val);
			idx++;
		} else if(t == 'L'){
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			tree.updateLock(0, 0, maxN, l, r, 1);
		} else if(t == 'C'){
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			tree.updateLock(0, 0, maxN, l, r, 0);
		} else if(t == 'O'){
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			cout << tree.querySum(0, 0, maxN, l, r) << "\n";
		}
	}
	
    return 0;
}

