#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
int parent[logN][maxN], depth[maxN];

void dfs(int curNode, int prvNode, int d = 0){
	parent[0][curNode] = prvNode;
	for(int x=1;x<logN;x++){
		parent[x][curNode] = parent[x-1][parent[x-1][curNode]];
	}
	depth[curNode] = d;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, d+1);
		}	
	}
}

pair<int, int> findLCA(int a, int b){
	bool swapped = false;
	if(depth[a] > depth[b]){
		swap(a, b);
		swapped = true;
	}
	
	for(int x=logN-1;x>=0;x--){
		if(depth[a] <= depth[b]-(1 << x)){
			b = parent[x][b];
		}
	}
	
	if(a == b) return (swapped ? b : a);
	
	for(int x=logN-1;x>=0;x--){
		if(parent[x][a] != parent[x][b]){
			a = parent[x][a];
			b = parent[x][b];
		}
	}
	
	return {parent[0][a], swapped ? b : a};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++) adj[x].clear();
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);	
		}
		
		int root = -1;
		for(int x=0;x<n;x++){
			if(adj[x].size() == 1){
				root = x;
				break;
			}
		}
		
		dfs(root, root);
		
		ll ans[n+1];
		fill(ans, ans+n+1, 0);
		
		int l = 0, r = 0;
		for(int x=0;x<n;x++){
			pair<int, int> pl = findLCA(l, x);
			pair<int, int> pr = findLCA(r, x);
			if(pl.first == pr.first){
				if(pl.second == pr.second){
					break;
				}
				continue;
			}
		}
	}
	
    return 0;
}

