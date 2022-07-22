#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 1e5 + 5;

struct SegmentTree {
	int tree[4*maxN];
	int lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}	
	
	void push(int v, int curL, int curM, int curR){
		if(lazy[v] == 0) return;
		
		tree[2*v+1] = (curM-curL+1) * (lazy[v]?1:0);
		lazy[2*v+1] += lazy[v];
		
		tree[2*v+2] = (curR-curM) * (lazy[v]?1:0);
		lazy[2*v+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			tree[v] = (curR-curL+1) * (val?1:0);
			lazy[v] += val;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		push(v, curL, curM, curR);
		
		update(2*v+1, curL, curM, l, min(curM, r), val);
		update(2*v+2, curM+1, curR, max(l, curM+1), r, val);
		
		tree[v] = tree[2*v+1] + tree[2*v+2];
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return 0;
		if(curL == l && curR == r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;
		
		push(v, curL, curM, curR);
		
		int ans = query(2*v+1, curL, curM, l, min(curM, r)) + query(2*v+2, curM+1, curR, max(l, curM+1), r);
		
		tree[v] = tree[2*v+1] + tree[2*v+2];
		return ans;
	}
} tree;

struct SegmentTreeMin {
	int tree[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 1e9);
	}	
	
	void update(int v, int curL, int curR, int pos, int val){
		if(curL > curR) return;
		if(curL == curR && curL == pos){
			tree[v] = min(tree[v], val);
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		if(pos <= curM){
			update(2*v+1, curL, curM, pos, val);
		} else {
			update(2*v+2, curM+1, curR, pos, val);
		}
		
		tree[v] = min(tree[2*v+1], tree[2*v+2]);
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return 1e9;
		if(curL == l && curR == r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;

		return min(query(2*v+1, curL, curM, l, min(curM, r)), query(2*v+2, curM+1, curR, max(l, curM+1), r));
	}
} mn, cur;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> v[k+1];
	int l[m], r[m], val[m];
	for(int x=0;x<m;x++){
		cin >> l[x] >> r[x] >> val[x];
		l[x]--; r[x]--;
		
		v[val[x]].push_back(x);
	}
	
	for(int x=1;x<=k;x++){
		cur.reset();
		vector<pair<int, int>> w;
		for(auto idx : v[x]){
			w.push_back({r[idx]-l[idx]+1, idx});
		}
		
		sort(w.begin(), w.end());
		
		vector<int> z;
		for(auto p : w){
			if(cur.query(0, 0, n-1, l[p.second], r[p.second]) > r[p.second]){
				z.push_back(p.second);
				cur.update(0, 0, n-1, l[p.second], r[p.second]);
			}
		}
		v[x] = z;
	}
	
	tree.reset();
	for(auto idx : v[1]){
		tree.update(0, 0, n-1, l[idx], r[idx], 1);
	}
		
	ll ans = 1;
	for(int x=2;x<=k;x++){
		if(v[x].empty()) continue;
		
		mn.reset();
		
		for(auto idx : v[x]){
			mn.update(0, 0, n-1, l[idx], r[idx]);
		}
		
		ll table[n];
		fill(table, table+n, 0);
		
		int lst = -1;
		for(int y=0;y<n;y++){
			if(tree.query(0, 0, n-1, y, y) > 0) continue;
			if(mn.query(0, 0, n-1, 0, y) < y) continue;
			
			lst = y;
			int bound = 0;
			int left = 0, right = y-1;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(mn.query(0, 0, n-1, mid, y-1) >= y){
					bound = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			ll cnt = 0;
			for(int z=bound;z<y;z++){
				cnt += table[z] * powmod(x-1, y-z-1-tree.query(0, 0, n-1, z+1, y-1)) % mod;
				cnt %= mod;
			}
			
			if(bound == 0){
				cnt += powmod(x-1, y-tree.query(0, 0, n-1, 0, y-1));
				cnt %= mod;
			}
			
			table[y] = cnt;
		}
		
		int bound = 0;
		int left = 0, right = lst;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(mn.query(0, 0, n-1, mid, n-1) >= lst){
				bound = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		ll val = 0;
		for(int y=bound;y<=lst;y++){
			if(tree.query(0, 0, n-1, y, y) > 0) continue;
			if(mn.query(0, 0, n-1, 0, y) < y || mn.query(0, 0, n-1, 0, y) < lst) continue;
			
//			cout << "= " << y << " " << table[y] << "*" << powmod(x-1, lst-y-tree.query(0, 0, n-1, y+1, lst)) << " " << tree.query(0, 0, n-1, y, y) << "\n";
			val += table[y] * powmod(x-1, lst-y-tree.query(0, 0, n-1, y+1, lst));
			val %= mod;
		}
		
		for(int y=0;y<n;y++){
			if(tree.query(0, 0, n-1, y, y) > 0) continue;
			if(mn.query(0, 0, n-1, 0, y) < y) continue;
			
			tree.update(0, 0, n-1, y, y, 1);
		}
		
		ans *= val;
		ans %= mod;
//		cout << x << " -> " << ans << " " << bound << "\n";
	}
	
	for(int x=0;x<n;x++){
		if(tree.query(0, 0, n-1, x, x) == 0){
			ans *= k;
			ans %= mod;
		}
	}
	cout << ans << "\n";
	return 0;
}
