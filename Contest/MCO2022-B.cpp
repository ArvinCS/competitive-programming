#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int sz[maxN], parent[maxN];

void dfs(int curNode, int prvNode){
	parent[curNode] = prvNode;
	sz[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			sz[curNode] += sz[nxt];
		}
	}
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
	
	dfs(0, -1);
	
	for(int x=0;x<n;x++){
		pair<int, int> mx = {-1, -1};
		
		for(auto nxt : adj[x]){
			mx = max(mx, {(nxt == parent[x] ? n-sz[x] : sz[nxt]), nxt});
		}
		
		cout << x+1 << " " << mx.second+1 << " " << mx.first << "\n";
	}
    return 0;
}

