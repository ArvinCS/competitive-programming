#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;
const ll mod = 998244353;

vector<int> adj[maxN], new_adj[maxN];
map<pair<int, int>, int> v[maxN];
int sz[maxN], level[maxN], parent[maxN], heavy[maxN], head[maxN], pos[maxN];
bool removed[maxN];
int t = 0;

struct SparseTable {
	int table[logN][maxN];
	
	void build(int n, int b[]){
		for(int x=0;x<n;x++){
			table[0][x] = b[x];
		}
		for(int x=1;x<logN;x++){
			int length = (1 << x);
			for(int y=0;y+length<=n;y++){
				table[x][y] = __gcd(table[x-1][y], table[x-1][y+length/2]);
			}
		}
	}
	
	int query(int l, int r){
		int lg = log2(r-l+1);
		int length = (1 << lg);
		
		return __gcd(table[lg][l], table[lg][r-length+1]);
	}
};

int dfs(int curNode, int prvNode = -1){
	int sz = 1;
	int mx = 0;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parent[nxt] = curNode;
			level[nxt] = level[curNode]+1;
			
			int sz2 = dfs(nxt, curNode);
			sz += sz2;
			
			if(sz2 > mx){
				mx = sz2;
				heavy[curNode] = nxt;
			}
		}
	}
	return sz;
}

void decompose(int curNode, int p){
	head[curNode] = p;
	pos[curNode] = t++;
		
	if(heavy[curNode] != -1){
		decompose(heavy[curNode], p);
	}
	for(auto nxt : adj[curNode]){
		if(nxt != parent[curNode] && nxt != heavy[curNode]){
			decompose(nxt, nxt);
		}
	}
}

void computeSize(int curNode, int prvNode = -1){
	sz[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode && !removed[nxt]){
			computeSize(nxt, curNode);
			sz[curNode] += sz[nxt];
		}
	}
}

int centroid(int curNode){
	computeSize(curNode);
	int curSize = sz[curNode];
	
	int root = curNode;
	bool found = false;
	while(!found){
		found = true;
		for(auto nxt : adj[root]){
			if(!removed[nxt] && sz[nxt] <= sz[root]){
				if(sz[nxt] > curSize/2){
					root = nxt;
					found = false;
					break;
				}
			}
		}
	}
	
	return root;
}

int build(int curNode){
	int root = centroid(curNode);
	removed[root] = true;
	
	for(auto nxt : adj[root]){
		if(!removed[nxt]){
			int nxtRoot = build(nxt);
			
			new_adj[root].push_back(nxtRoot);
			new_adj[nxtRoot].push_back(root);
		}
	}
	
	return root;
}

SparseTable table;

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (level[head[a]] > level[head[b]])
            swap(a, b);
        int val = table.query(pos[head[b]], pos[b]);
        res = __gcd(res, val);
    }
    if (level[a] > level[b])
        swap(a, b);
    int val = table.query(pos[a], pos[b]);
    res = __gcd(res, val);
    return res;
}

int dist(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (level[head[a]] > level[head[b]])
            swap(a, b);
        int val = pos[b]-pos[head[b]]+1;
        res += val;
    }
    if (level[a] > level[b])
        swap(a, b);
    int val = pos[b]-pos[a]+1;
    res += val;
    return res;
}

ll dfs2(int curNode, int prvNode){
	int val = query(curNode, curNode);
	ll ans = 0;
	
	v[curNode][{1, val}]++;
	for(auto nxt : new_adj[curNode]){
		if(nxt != prvNode){
			ans += dfs2(nxt, curNode);
			if(ans >= mod) ans -= mod;
			
			for(auto node : v[nxt]){
				ans += __gcd(val, node.first.second)*1ll*(node.first.first+dist(nxt, curNode)-1) % mod * node.second % mod;
				if(ans >= mod) ans -= mod;
				
				v[curNode][{node.first.first+dist(nxt, curNode)-1, __gcd(val, node.first.second)}] += node.second;
			}
		}
	}
	
	map<pair<int, int>, int> mp;
	for(int x=0;x<new_adj[curNode].size();x++){
		if(new_adj[curNode][x] == prvNode) continue;
		for(auto node : v[new_adj[curNode][x]]){
			for(auto p : mp){
				ans += __gcd(p.first.second, node.first.second)*1ll*(node.first.first+p.first.first) % mod * p.second % mod * node.second % mod;
				if(ans >= mod) ans -= mod;
			}
		}
		
		for(auto node : v[new_adj[curNode][x]]){
			cout << curNode << " " << new_adj[curNode][x] << " -> " << node.first.first << " + " << dist(new_adj[curNode][x], curNode)-1 << "\n";
			mp[{node.first.first+dist(new_adj[curNode][x], curNode)-1, __gcd(node.first.second, val)}] += node.second;
		}
		v[new_adj[curNode][x]].clear();
	}
	mp.clear();
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n-1;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	fill(heavy, heavy+n, -1);
	level[0] = 0;
	dfs(0);
	decompose(0, 0);
	
	fill(removed, removed+n, false);
	
	int root = build(0);
	
	int b[n];
	for(int x=0;x<n;x++){
		b[pos[x]] = a[x];
	}
	
	table.build(n, b);
	
	cout << dfs2(root, root) << "\n";
    return 0;
}

