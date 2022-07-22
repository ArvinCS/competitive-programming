#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 55;
const int maxK = 1e4 + 5;

vector<int> adj[maxN];
vector<int> cycle[maxK];
int color[maxN], parent[maxN], id = 0;

void dfs(int curNode, int prvNode){
	if(color[curNode] == 2){
		return;
	}
	
	cout << curNode << " " << prvNode << " -> " << color[curNode] << "\n";

	if(color[curNode] == 1){
		int node = prvNode;
		cycle[id].push_back(node);
		
		while(node != curNode){
			node = parent[node];
			cycle[id].push_back(node);
		}
		id++;
		return;
	}
	
	parent[curNode] = prvNode;
	color[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
		}
	}
	
	color[curNode] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	if(k > (1 << n)-1-n-n*(n-1)/2){
		cout << "NO\n";
		return 0;
	}
	
	fill(color, color+n, 0);
	
	color[0] = 1;
	for(auto nxt : adj[0]){
		dfs(nxt, 0);
	}
	color[0] = 2;
	
//	while(id < k){
//			
//	}
	
	cout << "YES\n";
	cout << id << "\n";
	return 0;
}
