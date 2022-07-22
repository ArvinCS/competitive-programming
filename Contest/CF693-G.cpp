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

const int maxN = 2e5 + 5;

int dist[maxN];
int dist2[maxN][2];
bool visited[maxN];

void bfs(int source, vector<int> adj[]){
	fill(dist, dist+maxN, -1);
	
	queue<pair<int, int>> q;
	q.push({0, source});
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();	
		
		if(dist[p.second] != -1) continue;
		
		dist[p.second] = p.first;
		for(auto nxt : adj[p.second]){
			q.push({p.first+1, nxt});
		}
	}
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
		
		vector<int> adj[n], adj2[n];
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj2[b].push_back(a);
		}
		
		bfs(0, adj);
		
		fill(visited, visited+n, false);
		fill(dist2[0], dist2[n], inf_int);
		
		vector<pair<int, int>> v;
		for(int x=0;x<n;x++){
			v.push_back({dist[x], x});
		}
		sort(v.begin(), v.end());
		
		for(auto p : v){
			int sourceNode = p.second;
			deque<pair<int, bool>> q;
			q.push_front(make_pair(sourceNode, false));
			while(!q.empty()){
				pair<int, bool> p = q.front();
				q.pop_front();
				
				int curNode = p.first;
				bool used = p.second;
				
				visited[curNode] = true;
				dist2[curNode][used] = min(dist2[curNode][used], dist[sourceNode]);
				for(auto nxt : adj2[curNode]){
					if(!visited[nxt]){ // if visited it guaranteed that ans[nxt] <= dist[sourceNode]
						if(dist[nxt] < dist[curNode]){
							q.push_front({nxt, used});
						} else {
							if(!used) q.push_back({nxt, true});
						}
					}
				}
			}
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << min(dist2[x][0], dist2[x][1]);
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

