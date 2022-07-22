#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
int sz[maxN], level[maxN], parent[logN][maxN], par[maxN];
bool removed[maxN];

void dfs(int curNode, int prvNode = -1){
	for(int x=1;x<logN;x++){
		parent[x][curNode] = parent[x-1][parent[x-1][curNode]];
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			level[nxt] = level[curNode]+1;
			parent[0][nxt] = curNode;
			dfs(nxt, curNode);
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

int findLCA(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN-1;x>=0;x--){
		if(level[a] <= level[b]-(1 << x)){
			b = parent[x][b];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN-1;x>=0;x--){
		if(parent[x][a] != parent[x][b]){
			a = parent[x][a];
			b = parent[x][b];
		}
	}
	
	return parent[0][a];
}

int getDist(int a, int b){
	return level[a]+level[b]-2*level[findLCA(a, b)];
}

int build(int curNode){
	int root = centroid(curNode);
	removed[root] = true;
	
	for(auto nxt : adj[root]){
		if(!removed[nxt]){
			int nxtRoot = build(nxt);
			
			par[nxtRoot] = root;
		}
	}
	
	return root;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	level[0] = parent[0][0] = 0;
	dfs(0);
	
	fill(removed, removed+n, false);
	fill(par, par+n, -1);
	
	int root = build(0);
	int ans[n];
	fill(ans, ans+n, 1e9);
	
	{
		int cur = 0;
		while(cur != -1){
			ans[cur] = min(ans[cur], getDist(cur, 0));
			cur = par[cur];
		}
	}
	
	for(int i=0;i<m;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int node;
			cin >> node;
			
			node--;
			int cur = node;
			while(cur != -1){
				ans[cur] = min(ans[cur], getDist(cur, node));
				cur = par[cur];
			}
		} else if(t == 2){
			int node;
			cin >> node;
			
			node--;
			int mn = 1e9;
			int cur = node;
			while(cur != -1){
				mn = min(mn, getDist(cur, node)+ans[cur]);
				cur = par[cur];
			}
			
			cout << mn << "\n";
		} else {
			assert(true);
		}
	}
	
    return 0;
}

