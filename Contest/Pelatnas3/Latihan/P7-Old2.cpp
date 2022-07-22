#include <bits/stdc++.h>



using namespace std;



#define ll long long



const int maxN = 2002;

const ll inf = 1e18;



//ll dist[maxN][maxN];

vector<pair<int, ll>> adj[maxN];



int main(){

	ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

	

	int n, m;

	cin >> n >> m;

	

//	fill(dist[0], dist[n], 1e18);

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

		

		ll prefix[n], suffix[n];

		fill(prefix, prefix+n, 0);

		fill(suffix, suffix+n, 0);

		

		ll cur = 0;

		priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;

		for(int x=0;x+1<l;x++){

			fill(dist[0], dist[n], 1e18);

			

			for(int y=0;y<adj[p[x]].size();y++){

				dist[adj[p[x]][y].first][p[x]] = (x == 0 ? 0 : min(y > 0 ? prefix[y-1] : inf, y+1 < adj[p[x]].size() ? suffix[y+1] : inf))+adj[p[x]][y].second;

				pq.push({dist[adj[p[x]][y].first][p[x]], p[x], adj[p[x]][y].first});

			}

			

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

			

			for(int y=0;y<adj[p[x+1]].size();y++){

				prefix[y] = (y > 0 ? prefix[y-1] : 1e18);

				prefix[y] = min(prefix[y], dist[p[x+1]][adj[p[x+1]][y].first]);

			}

			for(int y=adj[p[x+1]].size()-1;y>=0;y--){

				suffix[y] = (y+1 < adj[p[x+1]].size() ? suffix[y+1] : 1e18);

				suffix[y] = min(suffix[y], dist[p[x+1]][adj[p[x+1]][y].first]);

			}

		}

		

		cout << (suffix[0] != 1e18 ? suffix[0] : -1) << "\n";

	}

    return 0;

}



