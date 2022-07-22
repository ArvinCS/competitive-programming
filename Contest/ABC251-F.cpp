#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
vector<pair<int, int>> ans[2];
bool visited[maxN];

void dfs(int curNode){
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			ans[0].push_back({curNode, nxt});
			dfs(nxt);
		}
	}
}

void bfs(int curNode){
	queue<int> q;
	visited[curNode] = true;
	q.push(curNode);
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : adj[curNode]){
			if(!visited[nxt]){
				ans[1].push_back({curNode, nxt});
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(visited, visited+n, false);
	dfs(0);
	
	fill(visited, visited+n, false);
	bfs(0);
	
	for(int x=0;x<2;x++){
		for(auto p : ans[x]){
			cout << p.first+1 << " " << p.second+1 << "\n";
		}
	}
    return 0;
}

