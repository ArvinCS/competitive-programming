#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

struct SegTree {
	vector<ll> tree, lazy;
	
	int n;
	void resize(int m){
		n = m;
		tree = lazy = vector<ll>(4*n+5, 0);
	}
	
	void build(int v, int l, int r, ll cost[]){
		if(l > r) return;
		if(l == r){
			tree[v] = cost[l];
			lazy[v] = 0;
			return;
		}
		
		int m = (l+r) >> 1;
		build(v*2+1, l, m, cost);
		build(v*2+2, m+1, r, cost);
		
		tree[v] = max(tree[v*2+1], tree[v*2+2]);
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(curL > r || l > r || curL > curR) return;
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
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

const int maxN = 2e5 + 5;
const int logN = log2(maxN);

vector<pair<int, ll>> adj[maxN];
ll d[maxN], cost[2*maxN], edge[maxN];
int inTime[maxN], outTime[maxN], level[maxN], parrent[maxN][logN+5], t = 0;
SegTree tree;
vector<int> v;

void dfs(int curNode, int prvNode, ll val){
	for(int x=1;x<=logN;x++){
		parrent[curNode][x] = parrent[parrent[curNode][x-1]][x-1];
	}
	
	cost[t] = d[curNode]+val;
	inTime[curNode] = t++;
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			level[nxt.first] = level[curNode]+1;
			parrent[nxt.first][0] = curNode;
			edge[nxt.first] = nxt.second;
			
			dfs(nxt.first, curNode, val+nxt.second);
		}
	}
	
	outTime[curNode] = t++;
	v.push_back(curNode);
}

int lca(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN;x>=0;x--){
		if(level[a] <= level[b]-(1 << x)){
			b = parrent[b][x];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN;x>=0;x--){
		if(parrent[a][x] != parrent[b][x]){
			a = parrent[a][x];
			b = parrent[b][x];
		}
	}
	
	return parrent[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		a--; b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});	
	}
	
	for(int x=0;x<n;x++){
		cin >> d[x];
	}
	
	fill(cost, cost+2*n+5, 0);
	
	t = 0;
	
	level[0] = 0;
	parrent[0][0] = 0;
	dfs(0, 0, 0);
	
	t--;
	tree.resize(t);
	tree.build(0, 0, t, cost);
	
	reverse(v.begin(), v.end());
	
	ll ans[n];
	fill(ans, ans+n, 0);
	
	ans[0] = max(tree.query(0, 0, t, 0, inTime[0]-1), tree.query(0, 0, t, inTime[0]+1, t));
	
	for(int x=1;x<n;x++){
		int node = v[x-1], nxt = v[x];
		int lc = lca(node, nxt);
		
		while(node != lc){
			tree.update(0, 0, t, 0, t, -edge[node]);
			tree.update(0, 0, t, inTime[node], outTime[node], 2*edge[node]);
			
			node = parrent[node][0];
		}
		
		vector<int> w;
		while(nxt != lc){
			w.push_back(nxt);
			nxt = parrent[nxt][0];
		}
		
		for(int y=w.size()-1;y>=0;y--){
			node = w[y];
			
			tree.update(0, 0, t, 0, t, edge[node]);
			tree.update(0, 0, t, inTime[node], outTime[node], 2*(-edge[node]));
		}
		
		ans[v[x]] = max(tree.query(0, 0, t, 0, inTime[v[x]]-1), tree.query(0, 0, t, inTime[v[x]]+1, t));
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

