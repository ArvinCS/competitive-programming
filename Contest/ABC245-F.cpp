#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN], rev_adj[maxN];
bool visited[maxN];

void dfs(int curNode, vector<int> &v){
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt, v);
		}
	}	
	
	v.push_back(curNode);
}

void dfs2(int curNode, vector<int> &v){
	visited[curNode] = true;
	
	for(auto nxt : rev_adj[curNode]){
		if(!visited[nxt]){
			dfs2(nxt, v);
		}
	}	
	
	v.push_back(curNode);
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
		rev_adj[b].push_back(a);
	}
	
	fill(visited, visited+n, false);
	
	vector<int> topo;
	for(int x=0;x<n;x++){
		if(!visited[x]){
			dfs(x, topo);
		}
	}
	
	reverse(topo.begin(), topo.end());
	
	fill(visited, visited+n, false);
	
	vector<int> v;
	for(auto node : topo){
		if(!visited[node]){
			vector<int> comp;
			dfs2(node, comp);
			
			if(comp.size() > 1){
				for(auto node2 : comp){
					v.push_back(node2);
				}
			}
		}
	}
	
	fill(visited, visited+n, false);
	
	queue<int> q;
	for(auto node : v){
		if(!visited[node]){
			visited[node] = true;
			q.push(node);
		}
	}
	
	int cnt = 0;
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		cnt++;	
		for(auto nxt : rev_adj[curNode]){
			if(!visited[nxt]){
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
	
	cout << cnt << "\n";
    return 0;
}

