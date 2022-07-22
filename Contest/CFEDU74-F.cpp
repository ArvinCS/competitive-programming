#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

vector<int> adj[maxN];
int n, dist[maxN];

void bfs(int root){
	fill(dist, dist+n, -1);
	
	queue<int> q;
	q.push(root);
	dist[root] = 1;
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : adj[curNode]){
			if(dist[nxt] == -1){
				int sz = adj[nxt].size();
				dist[nxt] = dist[curNode]+1+max(0, sz-2);
				q.push(nxt);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
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
		
		int root = -1;
		for(int x=0;x<n;x++){
			if(adj[x].size() == 1){
				root = x;
				break;
			}
		}
		
		bfs(root);
		
		for(int x=0;x<n;x++){
			if(dist[x] > dist[root]){
				root = x;
			}
		}
		
		bfs(root);
		
		int ans = 0;
		for(int x=0;x<n;x++){
			ans = max(ans, dist[x]);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

