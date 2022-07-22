#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		
		return false;
	}
};

vector<pair<int, int>> adj[3][maxN];
int dist[3][maxN], level[3][maxN], parent[3][logN][maxN];
DSU dsu[3];

void dfs(int id, int curNode, int prvNode){
	for(int x=1;x<logN;x++){
		parent[id][x][curNode] = parent[id][x-1][parent[id][x-1][curNode]];
	}
	
	for(auto nxt : adj[id][curNode]){
		if(nxt.first != prvNode){
			dist[id][nxt.first] = dist[id][curNode]+nxt.second;
			level[id][nxt.first] = level[id][curNode]+1;
			parent[id][0][nxt.first] = curNode;
			dfs(id, nxt.first, curNode);
		}
	}
}

int findLCA(int id, int a, int b){
	if(level[id][a] > level[id][b]) swap(a, b);
	
	for(int x=logN-1;x>=0;x--){
		if(level[id][a] <= level[id][b]-(1 << x)){
			b = parent[id][x][b];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN-1;x>=0;x--){
		if(parent[id][x][a] != parent[id][x][b]){
			a = parent[id][x][a];
			b = parent[id][x][b];
		}
	}
	
	return parent[id][0][a];
}

int findDist(int id, int a, int b){
	return dist[id][a] + dist[id][b] - 2*dist[id][findLCA(id, a, b)];
}

int findLevel(int id, int a, int b){
	return level[id][a] + level[id][b] - 2*level[id][findLCA(id, a, b)];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<array<int, 3>> edge;
	for(int x=0;x<m;x++){
		int a, b, w;
		cin >> a >> b >> w;
		
		a--; b--;
		edge.push_back({a, b, w});
	}
	
	for(int x=0;x<3;x++){
		dsu[x].reset();
		vector<array<int, 3>> w;
		for(auto a : edge){
			w.push_back({(x == 0 ? (a[2] == 0) : a[2]&x), a[0], a[1]});
		}
		
		sort(w.begin(), w.end());
		
		for(auto a : w){
			if(dsu[x].merge(a[1], a[2])){
				cout << x << " -> " << a[1] << " " << a[2] << "\n";
				adj[x][a[1]].push_back({a[2], a[0]});
				adj[x][a[2]].push_back({a[1], a[0]});
			}
		}
		
		level[x][0] = parent[x][0][0] = 0;
		dist[x][0] = 0;
		
		dfs(x, 0, 0);
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		
		int ans = 0;
		for(int x=1;x<3;x++){
			if(findDist(x, u, v) != findLevel(x, u, v)){
				ans = x;
				break;
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

