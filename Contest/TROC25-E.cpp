#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const ll mod = 998244353;

struct SegTree { // index start from 0 (v)
	ll tree[4*maxN], lazy[4*maxN];
	
	void resize(){
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v, int l, int r, int m){
		tree[v*2+1] += (m-l+1)*lazy[v] % mod;
		lazy[v*2+1] += lazy[v];
		tree[v*2+1] %= mod;
		lazy[v*2+1] %= mod;
		
		tree[v*2+2] += (r-m)*lazy[v] % mod;
		lazy[v*2+2] += lazy[v];
		tree[v*2+2] %= mod;
		lazy[v*2+2] %= mod;
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] += (r-l+1)*val % mod;
			tree[v] %= mod;
			
			lazy[v] += val;
			lazy[v] %= mod;
		} else {		
			int curM = (curL+curR) >> 1;
			
			push(v, curL, curR, curM);
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = (tree[v*2+1] + tree[v*2+2]) % mod;
		}
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0ll;
		if(l <= curL && curR <= r){
			return tree[v] % mod;
		}
		
		int curM = (curL+curR) >> 1;
		
		push(v, curL, curR, curM);
		
		ll ans = query(v*2+1, curL, curM, l, min(r, curM));
		ans += query(v*2+2, curM+1, curR, max(l, curM+1), r);
		ans %= mod;
		
		return ans;
	}
};

vector<int> adj[maxN];
int l[maxN], r[maxN], parrent[maxN], pos[maxN], t = 0;
SegTree tree;

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			pos[nxt] = t++;
			parrent[nxt] = curNode;
			l[curNode] = min(l[curNode], pos[nxt]);
			r[curNode] = max(r[curNode], pos[nxt]);
		}
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x] %= mod;
	}
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		if(a == b) continue;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	tree.resize();
	
	fill(l, l+maxN, n);
	fill(r, r+maxN, -1);
	fill(parrent, parrent+maxN, -1);
	fill(pos, pos+n, -1);
	
	t = 0;
	pos[0] = t++;
	parrent[0] = -1;
	dfs(0, 0);
	
	for(int x=0;x<n;x++){
		assert(pos[x] >= 0);
		tree.update(0, 0, t-1, pos[x], pos[x], a[x]);
	}
	
	int q;
	cin >> q;
	
	for(int i=0;i<q;i++){
		int ty, node;
		cin >> ty >> node;
		
		node--;
		if(ty == 1){
			ll val = tree.query(0, 0, t-1, pos[node], pos[node]) % mod;
			
			if(l[node] <= r[node]){
				tree.update(0, 0, t-1, l[node], r[node], val);
			}
			if(parrent[node] != -1){
				tree.update(0, 0, t-1, pos[parrent[node]], pos[parrent[node]], val);
			}
		} else {
			ll ans = tree.query(0, 0, t-1, l[node], r[node]);
			
			if(parrent[node] != -1){
				ans += tree.query(0, 0, t-1, pos[parrent[node]], pos[parrent[node]]);
				ans %= mod;
			}
			
			cout << ans << "\n";
		}
	}
    return 0;
}

