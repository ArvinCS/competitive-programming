#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
int parent[logN][maxN], sz[maxN], depth[maxN];
int c[maxN];

void dfs(int curNode, int prvNode, int d = 1){
	parent[0][curNode] = prvNode;
	for(int x=1;x<logN;x++){
		parent[x][curNode] = parent[x-1][parent[x-1][curNode]];
	}
	sz[curNode] = 1;
	depth[curNode] = d;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, d+1);
			sz[curNode] += sz[nxt];
		}
	}
}

int dfs2(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode && sz[nxt] > sz[0]/2){
			return dfs2(nxt, curNode);
		}
	}
	return curNode;
}

int findLCA(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	
	for(int x=logN-1;x>=0;x--){
		if(depth[a] <= depth[b]-(1 << x)){
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0, 0);
	
	int center = dfs2(0, 0);
	
	dfs(center, center);
	
	int l = center, r = center;
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		v.push_back({sz[x], x});
	}
	
	sort(v.rbegin(), v.rend());
	
	int ans[n+1], cur = 1;
	fill(ans, ans+n+1, 0);
	for(int x=0;x<n;x++){
		int idx = v[x].second;
		
		int d1 = depth[l]+depth[idx]-2*depth[findLCA(l, idx)]+1;
		int d2 = depth[r]+depth[idx]-2*depth[findLCA(r, idx)]+1;
		if(d1 < d2){
			swap(d1, d2);
			swap(l, r);
		}
		if(d1 > cur){
			cur = d1;
			r = idx;
		}
		
		ans[v[x].first] = cur;
	}
	
	for(int x=n-1;x>=0;x--){
		ans[x] = max(ans[x], ans[x+1]);
	}
	
	for(int x=1;x<=n;x++){
		if(x&1){
			cout << "1\n";
		} else {
			cout << ans[x>>1] << "\n";
		}
	}
    return 0;
}

