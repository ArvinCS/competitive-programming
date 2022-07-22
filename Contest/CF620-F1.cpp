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

const int maxM = 5e4 + 5;
struct SegTree { // index start from 0 (v)
	ll tree[4*maxM+5], lazy[4*maxM+5];
	
	int n;
	void reset(int n){
		this->n = n;
		
		fill(tree, tree+4*maxM+5, 0);
		fill(lazy, lazy+4*maxM+5, 0);
	}
	
	void build(int v, int l, int r, ll table[]){
		if(l > r) return;
		if(l == r){
			tree[v] = table[l];
			lazy[v] = 0;
			return;
		}
		
		int m = (l+r) >> 1;
		build(v*2+1, l, m, table);
		build(v*2+2, m+1, r, table);
		
		tree[v] = max(tree[v*2+1], tree[v*2+2]);
		lazy[v] = 0;
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = max(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	ll a[n][m+k];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
			if(y > 0) a[x][y] += a[x][y-1];
		}
		for(int y=m;y<m+k;y++){
			a[x][y] = a[x][y-1];
		}
	}
	
	tree.reset(m+k);
	
	ll table[m+k+1];
	fill(table, table+m+k+1, 0);
	
	for(int y=0;y<m;y++){
		table[y] = a[0][y+k-1] - (y > 0 ? a[0][y-1] : 0) + (n > 1 ? a[1][y+k-1] - (y > 0 ? a[1][y-1] : 0) : 0);
	}
	
	for(int x=1;x<n;x++){
		tree.build(0, 0, m+k-1, table);
		
		fill(table, table+m+k+1, 0);
		
		for(int y=0;y<k-1;y++){
			ll sum = a[x][y] - (y > 0 ? a[x][y-1] : 0);
			tree.update(0, 0, m+k-1, 0, y, -sum);
		}
		
		for(int y=0;y<m;y++){
			ll nxt = a[x][y+k-1] - (y+k-1 > 0 ? a[x][y+k-2] : 0);
			tree.update(0, 0, m+k-1, y, y+k-1, -nxt);
			
			if(y > 0){
				ll prv = a[x][y-1] - (y-1 > 0 ? a[x][y-2] : 0);
				tree.update(0, 0, m+k-1, max(0, y-k), y-1, prv);
			}
			
			ll sum = a[x][y+k-1] - (y > 0 ? a[x][y-1] : 0) + (x+1 < n ? a[x+1][y+k-1] - (y > 0 ? a[x+1][y-1] : 0) : 0);
			table[y] = sum+tree.query(0, 0, m+k-1, 0, m-1);
		}
	}
	
	ll ans = 0;
	for(int y=0;y<m;y++){
		ans = max(ans, table[y]);
	}
	
	cout << ans << "\n";
    return 0;
}

