#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

vector<int> toposort;

bool cycle(int curNode, bool visited[], bool tmp[], vector<int> adj[]){
	visited[curNode] = tmp[curNode] = true;
	bool ans = false;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]) ans |= cycle(nxt, visited, tmp, adj);
		else if(tmp[nxt]) ans = true;
	}
	tmp[curNode] = false;
	return ans;
}

void dfs(int curNode, bool visited[], vector<int> adj[]){
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt, visited, adj);
		}
	}
	toposort.push_back(curNode);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector<int> adj[n+1], adj2[n+1];
		vector<pair<int, int>> undirected;
		for(int x=0;x<m;x++){
			int c, a, b;
			cin >> c >> a >> b;
			
			if(c == 1){
				adj[a].push_back(b);
				adj2[b].push_back(a);
			} else {
				undirected.push_back({a, b});
			}
		}
		
		bool visited[n+1], visited2[n+1];
		for(int x=0;x<=n;x++){
			visited[x] = visited2[x] = false;
		}
		
		bool safe = true;
		for(int x=1;x<=n;x++){
			if(!visited[x] && cycle(x, visited, visited2, adj)){
				safe = false;
			}
		}
		
		if(!safe){
			cout << "NO\n";
			continue;
		}
		
		for(int x=0;x<=n;x++){
			visited[x] = false;
		}
		
		toposort.clear();
		for(int x=1;x<=n;x++){
			if(!visited[x]){
				dfs(x, visited, adj);
			}
		}
		reverse(toposort.begin(), toposort.end());
		
		int level[n+1];
		fill(level, level+n+1, -1);
		
		for(int x=0;x<toposort.size();x++){
			level[toposort[x]] = x;
		}
		
		vector<pair<int, int>> ans;
		for(auto p : undirected){
			if(level[p.first] > level[p.second]){
				ans.push_back({p.second, p.first});
			} else {
				ans.push_back({p.first, p.second});
			}
		}
		
		cout << "YES\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
		for(int x=1;x<=n;x++){
			for(auto nxt : adj[x]){
				cout << x << " " << nxt << "\n";
			}
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

