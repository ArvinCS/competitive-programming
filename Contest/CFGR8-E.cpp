#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> in[maxN], ot[maxN];
vector<int> adj[3*maxN];

struct DSU {
	int parent[3*maxN], sz[3*maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
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
} dsu;

void dfs(int curNode, bool visited[], vector<int> &v){
	visited[curNode] = true;
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			dfs(nxt, visited, v);
		}
	}
	v.push_back(curNode);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<=n;x++){
			in[x].clear();
			ot[x].clear();
		}
		for(int x=0;x<=3*n;x++){
			adj[x].clear();
		}
		dsu.reset(n);
		
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			ot[a].push_back(b);
			in[b].push_back(a);
		}
		
		vector<pair<int, int>> v;
		for(int x=0;x<n;x++){
			for(auto l : in[x]){
				for(auto r : ot[x]){
					v.push_back({l, r});
				}
			}
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		auto addClause = [&](int l, int r) -> void {
			cout << (l^1) << " " << r << "\n";
			if(l != r) cout << (r^1) << " " << l << "\n";
			adj[l^1].push_back(r);
			if(l != r) adj[r^1].push_back(l);
		};
		
		for(auto p : v){
			if(dsu.merge(p.first, p.second)){
				cout << p.first << " " << p.second << " -- 1\n";
				addClause(p.first << 1, p.second << 1);
//				addClause((p.first << 1)|1, (p.second << 1)|1);
			} else {
				cout << p.first << " " << p.second << " -- 2\n";
				addClause(p.first << 1, p.second << 1);
				addClause(p.first << 1, p.first << 1);
//				addClause(p.first << 1, p.second << 1);
//				addClause((p.second << 1)|1, (p.second << 1)|1);
			}
		}
		
		bool visited[3*n];
		fill(visited, visited+3*n, false);
		
		vector<int> topo;
		for(int x=0;x<2*n;x++){
			if(!visited[x]){
				dfs(x, visited, topo);
			}
		}
		
		int scc[3*n];
		fill(scc, scc+3*n, -1);
		
		reverse(topo.begin(), topo.end());
		fill(visited, visited+3*n, false);
		
		int idx = 0;
		for(auto curNode : topo){
			if(!visited[curNode]){
				vector<int> comp;
				dfs(curNode, visited, comp);
				
				for(auto node : comp){
					cout << node/2 << " " << (node&1) << " -\n";
					scc[node] = idx;
				}cout << "DONE\n";
				idx++;
			}
		}
		
		vector<int> ans, ans2;
		for(int x=0;x<n;x++){
//			assert(scc[((x+1) << 1)] != scc[((x+1) << 1) | 1]);
			cout << x << " -> " << scc[(x<<1)] << " " << scc[(x<<1)^1] << "\n";
			if(scc[(x << 1)] >= scc[(x << 1) ^ 1]){
				ans.push_back(x+1);
			} else{
				ans2.push_back(x+1);
			}
		}
		
//		if(ans.size() > 4 * n / 7){
//			swap(ans, ans2);
//		}
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

