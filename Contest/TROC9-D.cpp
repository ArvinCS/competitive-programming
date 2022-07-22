#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf_ll = 1e17;
const int maxN = 1e5 + 5;

ll t[maxN];
ll add;

struct SegTree {
	ll tree[4*maxN][2];
	ll lazy[4*maxN];
	
	void build(int v, int l, int r){
		if(l > r) return;
		if(l == r){
			tree[v][0] = tree[v][1] = (t[l] + add*l);
			return;
		}
		
		int m = (l+r) >> 1;
		build(v*2+1, l, m);
		build(v*2+2, m+1, r);
		
		tree[v][0] = max(tree[v*2+1][0], tree[v*2+2][0]);
		tree[v][1] = min(tree[v*2+1][1], tree[v*2+2][1]);
	}
	
	void push(int v){
		tree[v*2+1][0] += lazy[v];
		tree[v*2+1][1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2][0] += lazy[v];
		tree[v*2+2][1] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v][0] += val;
			tree[v][1] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v][0] = max(tree[v*2+1][0], tree[v*2+2][0]);
			tree[v][1] = min(tree[v*2+1][1], tree[v*2+2][1]);
		}
	}
	
	ll queryMax(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return -inf_ll;
		if(l <= curL && curR <= r){
			return tree[v][0];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(queryMax(v*2+1, curL, curM, l, min(r, curM)), queryMax(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
	
	ll queryMin(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return inf_ll;
		if(l <= curL && curR <= r){
			return tree[v][1];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return min(queryMin(v*2+1, curL, curM, l, min(r, curM)), queryMin(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

SegTree leftTree, rightTree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<n;x++){
		cin >> t[x];
	}
	
	add = -1;
	leftTree.build(0, 0, n-1);
	add = 1;
	rightTree.build(0, 0, n-1);
	
	for(int i=1;i<=q;i++){
		int p, x, y;
		ll val;
		cin >> p >> x >> y >> val;
		
		x--; y--;
		if(p == 1){			
			leftTree.update(0, 0, n-1, x, y, val);
			rightTree.update(0, 0, n-1, x, y, val);
		} else {
			val--;
			
			ll ans = 0;
			if(x <= val && val <= y){
				ll mxL = leftTree.queryMax(0, 0, n-1, x, val) + val;
				ll mxR = rightTree.queryMax(0, 0, n-1, val, y) - val;
				
				ll mnL = leftTree.queryMin(0, 0, n-1, x, val) + val;
				ll mnR = rightTree.queryMin(0, 0, n-1, val, y) - val;
				
				ans = max(mxL, mxR)-min(mnL, mnR);
			} else if(val < x){
				ll mxR = rightTree.queryMax(0, 0, n-1, x, y) - val;
				ll mnR = rightTree.queryMin(0, 0, n-1, x, y) - val;
				
				ans = mxR-mnR;
			} else if(y < val){
				ll mxL = leftTree.queryMax(0, 0, n-1, x, y) + val;
				ll mnL = leftTree.queryMin(0, 0, n-1, x, y) + val;
				
				ans = mxL-mnL;
			}
			
			cout << ans << "\n";
		}
	}
    return 0;
}

