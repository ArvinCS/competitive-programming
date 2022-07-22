#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 4e5 + 5;

vector<int> adj[maxN];
int sub[maxN];

int dfs(int curNode, int prvNode){
	sub[curNode] = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			sub[curNode] = max(sub[curNode], dfs(nxt, curNode));
		}
	}
	
	return sub[curNode]+1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		for(int x=0;x<=n;x++){
			adj[x].clear();
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int root = 0;
		int dist[n+1];
		queue<pair<int, int>> q;
		
		for(int i=0;i<2;i++){
			fill(dist, dist+n, 1e9);
			
			dist[root] = 0;
			q.push({dist[root], root});
			
			while(!q.empty()){
				pair<int, int> p = q.front();
				q.pop();
				
				if(dist[p.second] < p.first) continue;
				if(dist[root] < p.first){
					root = p.second;
				}
				
				for(auto nxt : adj[p.second]){
					if(dist[nxt] > p.first+1){
						dist[nxt] = p.first+1;
						q.push({dist[nxt], nxt});
					}
				}
			}
		}
		
		int dist2[n+1];
		fill(dist2, dist2+n, 1e9);
		
		dist2[root] = 0;
		q.push({dist2[root],  root});
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(dist2[p.second] < p.first) continue;
			if(dist2[root] < p.first){
				root = p.second;
			}
			
			for(auto nxt : adj[p.second]){
				if(dist2[nxt] > p.first+1){
					dist2[nxt] = p.first+1;
					q.push({dist2[nxt], nxt});
				}
			}
		}
		
		if(dist2[root] % 2 == 0){
			for(int x=0;x<n;x++){
				if(dist2[x] == dist2[root]/2 && dist[x] == (dist2[root])/2){
					root = x;
					break;
				}
			}
		} else {
			for(int x=0;x<n;x++){
				if(dist[x] == dist2[root]/2 && dist2[x] == (dist2[root]+1)/2){
					adj[n].push_back(x);
					int part = -1, pos = -1;
					for(int y=0;y<adj[x].size();y++){
						int nxt = adj[x][y];
						if(dist[nxt] == (dist2[root]+1)/2 && dist2[nxt] == dist2[root]/2){
							part = nxt;
							pos = y;
							adj[n].push_back(nxt);
							break;
						}
					}
					adj[x].erase(adj[x].begin()+pos);
					
					for(int y=0;y<adj[part].size();y++){
						if(adj[part][y] == x){
							pos = y;
							break;
						}
					}
					adj[part].erase(adj[part].begin()+pos);
					break;
				}
			}
			
			root = n;
		}
		
		dfs(root, root);
		
		int ans = 0;
		for(int x=0;x<n;x++){
			if(sub[x] >= k){
				ans++;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

