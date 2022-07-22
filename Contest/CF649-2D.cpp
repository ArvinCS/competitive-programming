#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<int> adj[maxN];
int visited[maxN], parrent[maxN], color[maxN], mark[maxN], source, k;
vector<int> cycle;

void dfs(int curNode, int prvNode){
	if(visited[curNode] == 1){
		source = curNode;
		return;	
	}
	
	parrent[curNode] = prvNode;
	visited[curNode] = 1;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode && visited[nxt] != 2){
			dfs(nxt, curNode);
		}
	}
	visited[curNode] = 2;
}

void dfs2(int curNode, int prvNode, int c){
	color[curNode] = c;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs2(nxt, curNode, c^1);		
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m >> k;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
		
	fill(visited, visited+n, 0);
	
	source = -1;
	dfs(0, 0);
	
	if(source != -1){ // check the cycle is exist or not.
		fill(visited, visited+n, 0);
		fill(parrent, parrent+n, -1);
		
		queue<int> q;
		visited[source] = 1;
		
		for(int x=0;x<adj[source].size();x++){
			int nxt = adj[source][x];
			
			if(parrent[source] != nxt && parrent[nxt] != source){
				visited[nxt] = 1;
				parrent[nxt] = source;
				mark[nxt] = x;
				q.push(nxt);
			}
		}
		
		while(!q.empty()){ // we find random cycle using bfs/dijkstra
			int curNode = q.front();
			q.pop();
			
			if(cycle.size() > 0) break;
			for(auto nxt : adj[curNode]){
				if(parrent[curNode] != nxt && parrent[nxt] != curNode){
					if(visited[nxt] == 0){
						visited[nxt] = 1;
						parrent[nxt] = curNode;
						mark[nxt] = mark[curNode];
						q.push(nxt);
					} else if(mark[curNode] != mark[nxt]){ // combine 2 node path, make sure their LCA is the root.
						int tmp = curNode;
						while(tmp != -1){
							cycle.push_back(tmp);
							tmp = parrent[tmp];
						}
						
						reverse(cycle.begin(), cycle.end());
						
						tmp = nxt;
						while(tmp != -1){
							cycle.push_back(tmp);
							tmp = parrent[tmp];
						}
						
						if(cycle.front() == cycle.back()) cycle.pop_back(); // remove duplicated endpoint.
						break;
					}
				}
			}
		}
		
		if(cycle.size() <= k){ // if cycle length <= k then print it.
			cout << 2 << "\n";
			cout << cycle.size() << "\n";
			for(int x=0;x<cycle.size();x++){
				if(x > 0) cout << " ";
				cout << cycle[x]+1;
			}
			cout << "\n";
		} else { // this means that we can pick (k+1)/2 node from the cycle itself.
			cout << 1 << "\n";
			for(int x=0;x<(k+1)/2;x++){
				if(x > 0) cout << " ";
				cout << cycle[2*x]+1;
			}
			cout << "\n";
		}
	} else { // this means this graph is simple (no cycle), just color it and print it.
		dfs2(0, 0, 0);
		
		vector<int> zero, one;
		for(int x=0;x<n;x++){
			if(color[x] == 0){
				zero.push_back(x);
			} else {
				one.push_back(x);
			}
		}
		
		if(one.size() > zero.size()) swap(one, zero);
		
		cout << 1 << "\n";
		for(int x=0;x<(k+1)/2;x++){
			if(x > 0) cout << " ";
			cout << zero[x]+1;
		}
		cout << "\n";
	}
		
    return 0;
}
