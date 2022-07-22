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
	
	// works for distinct x's
	set<int> st;
	vector<pair<int, int>> v;
	int l[m], r[m], val[m];
	for(int x=0;x<m;x++){
		cin >> l[x] >> r[x] >> val[x];
		l[x]--; r[x]--;
		v.push_back({val[x], x});
		assert(!st.count(val[x]));
		st.insert(val[x]);
	}
	
	sort(v.begin(), v.end());
	tree.reset();
	
	ll ans = 1;
	for(auto p : v){
		int idx = p.second;
		int v = val[idx];
		int length = (r[idx]-l[idx]+1)-tree.query(0, 0, n-1, l[idx], r[idx]);
//		cout << v << " -> " << length << "\n";
		if(length > 0){
			ans *= (powmod(v, length) - powmod(v-1, length) + mod) % mod;
//			cout << length << " " << (powmod(v, length) - powmod(v-1, length) + mod) % mod << " " << v << " -\n";
			ans %= mod;
			tree.update(0, 0, n-1, l[idx], r[idx], 1);
		} else {
			ans = 0;
			break;
		}
	} // 5*5*3
	for(int x=0;x<n;x++){
//		cout << x << " = " << tree.query(0, 0, n-1, x, x) << "\n";
		if(tree.query(0, 0, n-1, x, x) == 0){
			ans *= k;
			ans %= mod;
		}
	}
	cout << ans << "\n";
	return 0;
}
