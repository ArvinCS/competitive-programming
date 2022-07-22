#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct SegTree { // index start from 0 (v)
	pair<int, int> tree[4*maxN];
	int lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, make_pair(-1e9, -1));
		fill(lazy, lazy+4*maxN, 0);	
	}
	
	void build(int v, int l, int r, int val[]){
		if(l == r){
			tree[v] = {val[l], l};
			return;
		}
		
		int m = (l+r) >> 1;
		build(v*2+1, l, m, val);
		build(v*2+2, m+1, r, val);
		tree[v] = max(tree[v*2+1], tree[v*2+2]);
	}
	
	void push(int v){
		tree[v*2+1].first += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2].first += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
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
	
	pair<int, int> query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return {-1e9, -1};
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

int inTime[maxN], outTime[maxN], level[maxN], parent[maxN], id[maxN], t = 0;
vector<int> adj[maxN], leaves;
SegTree tree;

void dfs(int curNode, int prvNode){
	id[t] = curNode;
	inTime[curNode] = t++;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parent[nxt] = curNode;
			level[nxt] = level[curNode]+1;
			dfs(nxt, curNode);
		}
	}
	
	outTime[curNode] = t-1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parent[0] = -1;
	level[0] = 1;
	dfs(0, 0);
	
	tree.reset();
	
	int val[n];
	fill(val, val+n, -1e9);
	
	for(int x=1;x<n;x++){
		if(adj[x].size() == 1){
			val[inTime[x]] = level[x];
		}
	}
	
	tree.build(0, 0, n-1, val);
	
	bool mark[n];
	fill(mark, mark+n, false);
	
	ll ans = -1e18;
	int w = 0, r = 0, b = n;
	for(int i=1;i<=k;i++){
		pair<int, int> mx = tree.query(0, 0, n-1, 0, n-1);
		
		if(mx.first < 0){
			break;
		}
		
		int node = id[mx.second];
		
		w--;
		r++;
		while(node >= 0){
			if(mark[node]) break;
			
			tree.update(0, 0, n-1, inTime[node], outTime[node], -1);
			w++;
			b--;
			mark[node] = true;
			
			node = parent[node];
		}
		
		ll mn = w*1ll*(r-b);
		int left = 0, right = b-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			ll cur = (w+b-mid)*1ll*(r-mid);
			ll nxt = (w+b-mid-1)*1ll*(r-mid-1);
			
			mn = min(mn, cur);
			
			if(cur > nxt){
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		ans = max(ans, mn);
	}
	
	for(int x=r;x<=k;x++){
		ll mn = (w-(x-r))*1ll*(x-b);
		
		int left = 0, right = b-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			ll cur = (w+b-mid-(x-r))*1ll*(x-mid);
			ll nxt = (w+b-mid-1-(x-r))*1ll*(x-mid-1);
			
			mn = min(mn, cur);
			
			if(cur > nxt){
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		ans = max(ans, mn);
	}
	
	cout << ans << "\n";
    return 0;
}

