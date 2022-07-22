#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

vector<int> adj[maxN], adj_rev[maxN];
bool visited[maxN];

void dfs1(int curNode, vector<int> &v){
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs1(nxt, v);
		}
	}
	v.push_back(curNode);
}

void dfs2(int curNode, vector<int> &v){
	visited[curNode] = true;
	for(auto nxt : adj_rev[curNode]){
		if(!visited[nxt]){
			dfs2(nxt, v);
		}
	}
	v.push_back(curNode);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			adj_rev[x].clear();
		}
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			if(a == b) continue;
			
			adj[a].push_back(b);
			adj_rev[b].push_back(a);
		}
		
		fill(visited, visited+n, false);
		
		vector<int> topo;
		for(int x=0;x<n;x++){
			if(!visited[x]){
				dfs1(x, topo);
			}
		}
		
		reverse(topo.begin(), topo.end());
		fill(visited, visited+n, false);
		
		int cnt = 0;
		vector<int> a, b;
		for(auto node : topo){
			if(!visited[node]){
				vector<int> comp;
				dfs2(node, comp);
				
				if(cnt == 0){
					for(auto node2 : comp){
						b.push_back(node2);
					}
				} else {
					for(auto node2 : comp){
						a.push_back(node2);
					}
				}
				cnt++;
			}
		}
		
		if(cnt > 1 && min(a.size(), b.size()) > 0 && a.size()+b.size() == n){
			cout << "Yes\n";
			cout << a.size() << " " << b.size() << "\n";
			for(int x=0;x<a.size();x++){
				if(x > 0) cout << " ";
				cout << a[x]+1;
			}
			cout << "\n";
			for(int x=0;x<b.size();x++){
				if(x > 0) cout << " ";
				cout << b[x]+1;
			}
			cout << "\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
}
