#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2002;
const ll inf = 1e18;

map<int, vector<pair<ll, int>>> w[maxN][maxN];
vector<pair<int, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
//	for(int x=0;x<n;x++){
//		dist[x][x] = 0;
//	}
	for(int x=0;x<m;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		a--; b--;
//		dist[a][b] = c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
//	for(int x=0;x<n;x++){
//		for(int y=0;y<n;y++){
//			for(int z=0;z<n;z++){
//				dist[x][z] = min(dist[x][z], dist[x][y]+dist[y][z]);
//			}
//		}
//	}
	
	int l;
	cin >> l;
	
	int p[l];
	for(int x=0;x<l;x++){
		cin >> p[x];
		p[x]--;
	}
	
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
	for(int x=0;x<n;x++){
		ll dist[n][n];
		for(int y=0;y<adj[x].size();y++){
			fill(dist[0], dist[n], 1e18);
			dist[adj[x][y].first][x] = adj[x][y].second;
			pq.push({dist[adj[x][y].first][x], x, adj[x][y].first});
			
			while(!pq.empty()){
				ll d = pq.top()[0];
				int prv = pq.top()[1];
				int curNode = pq.top()[2];
				pq.pop();
				
				if(dist[curNode][prv] < d) continue;
				for(auto nxt : adj[curNode]){
					if(nxt.first != prv && dist[nxt.first][curNode] > d+nxt.second){
						dist[nxt.first][curNode] = d+nxt.second;
						pq.push({d+nxt.second, curNode, nxt.first});
					}
				}
			}
			
			for(int z=0;z<n;z++){
				vector<pair<ll, int>> v;
				for(auto prv : adj[z]){
					v.push_back({dist[z][prv.first], prv.first});
				}
				
				sort(v.begin(), v.end());
				
				for(int a=0;a<min(2, (int) v.size());a++){
					w[x][z][y].push_back(v[a]);
				}
				
				v.clear();
			}
		}
		
//		for(int y=0;y<adj[].size();y++){
//			prefix[y] = (y > 0 ? prefix[y-1] : 1e18);
//			prefix[y] = min(prefix[y], dist[p[x+1]][adj[p[x+1]][y].first]);
//		}
//		for(int y=adj[p[x+1]].size()-1;y>=0;y--){
//			suffix[y] = (y+1 < adj[p[x+1]].size() ? suffix[y+1] : 1e18);
//			suffix[y] = min(suffix[y], dist[p[x+1]][adj[p[x+1]][y].first]);
//		}
	}
		
	int t;
	cin >> t;
	
	while(t--){ // O(TL(N + MlogN))
		int a, b;
		cin >> a >> b;
		
		a--;
		b--;
		p[a] = b;
		
		ll dist[n][n];
		fill(dist[0], dist[n], 1e18);
		
		vector<pair<ll, int>> best[l];
		best[0].push_back({0, -1});
		
		for(int x=0;x+1<l;x++){
			for(int y=0;y<adj[p[x]].size();y++){
				for(auto mn : best[x]){
					if(mn.second == adj[p[x]][y].first) continue;
					for(auto mn2 : w[p[x]][p[x+1]][y]){
						best[x+1].push_back({mn.first+mn2.first, mn2.second});
					}
				}
			}
			
			sort(best[x+1].begin(), best[x+1].end());
			while(best[x+1].size() > 2){
				best[x+1].pop_back();
			}
			
			for(auto pa : best[x]){
				cout << p[x] << " -> " << pa.first << " " << pa.second << "\n";
			}
		}
		
		ll ans = 1e18;
		for(auto mn : best[l-1]){
			ans = min(ans, mn.first);
		}
		cout << (ans != 1e18 ? ans : -1) << "\n";
	}
    return 0;
}

