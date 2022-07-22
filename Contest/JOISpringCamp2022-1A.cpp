#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5;
const int maxM = 2e5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
int parent[logN][maxN], level[maxN];

void dfs(int curNode, int prvNode){
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	while(q--){
		int n;
		cin >> n;
		
		for(int x=0;x<=n;x++){
			adj[x].clear();
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int m;
		cin >> m;
		
		int s[m], t[m];
		for(int x=0;x<m;x++){
			cin >> s[x] >> t[x];
		}
		
		level[1] = 1;
		parent[0][1] = 1;
		dfs(1, 1);
		
		vector<int> v[n+1];
		for(int x=0;x<m;x++){
			v[s[x]].push_back(x);
			v[t[x]].push_back(x);
		}
		
		bool valid = true;
		for(int x=0;x<m;x++){
			int lca = findLCA(s[x], t[x]);
			
			set<int> st;
			
			int node = s[x];
			while(node != lca){
				node = parent[0][node];
				for(auto idx : v[node]){
					if(st.count(idx)){
						valid = false;
					} else {
						st.insert(idx);
					}
				}
			}
			
			node = t[x];
			while(node != lca && parent[0][node] != lca){
				node = parent[0][node];
				for(auto idx : v[node]){
					if(st.count(idx)){
						cout << "B\n";
						valid = false;
					} else {
						st.insert(idx);
					}
				}
			}
			
			cout << x << " -> " << valid << "\n";
		}
		
		cout << (valid ? "Yes" : "No") << "\n";
	}
	
    return 0;
}

