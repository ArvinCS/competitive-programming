#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<tuple<int, ll, int>> adj[maxN];
ll dist[maxN][3]; // [Nodes][from S / from U / from V]

void dijkstra(int source, int id){
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[source][id] = 0;
	pq.push({dist[source][id], source});
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second][id] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[get<0>(nxt)][id] > p.first+get<1>(nxt)){
				dist[get<0>(nxt)][id] = p.first+get<1>(nxt);
				
				pq.push({dist[get<0>(nxt)][id], get<0>(nxt)});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int s, t;
	cin >> s >> t;
	s--; t--;
	
	int u, v;
	cin >> u >> v;
	u--; v--;
	
	for(int x=0;x<m;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		a--; b--;
		adj[a].push_back(make_tuple(b, c, x));
		adj[b].push_back(make_tuple(a, c, x));
	}
	
	fill(dist[0], dist[maxN], 1e18);
	
	dijkstra(u, 1);
	dijkstra(v, 2);
	
	// special dijkstra 
	ll table[n][3][2];
	fill(*table[0], *table[n], 1e18);
	
	for(int x=0;x<n;x++){
		table[x][0][0] = table[x][0][1] = 0;
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[s][0] = 0;
	table[s][1][0] = dist[s][1];
	table[s][1][1] = dist[s][2];
	
	pq.push({dist[s][0], s});
			
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		ll cost = p.first;
		int curNode = p.second;
		
		if(dist[curNode][0] < cost) continue;
		for(auto nxt : adj[curNode]){
			if(dist[get<0>(nxt)][0] > cost+get<1>(nxt)){
				dist[get<0>(nxt)][0] = cost+get<1>(nxt);
				
				for(int x=0;x<3;x++){
					for(int y=0;y<2;y++){
						table[get<0>(nxt)][x][y] = table[curNode][x][y];
					}
				}
				
				for(int x=0;x<2;x++){
					if(table[curNode][x][0] != 1e18) table[get<0>(nxt)][x+1][0] = min(table[get<0>(nxt)][x+1][0], table[curNode][x][0]+dist[get<0>(nxt)][x+1]);
					if(table[curNode][x][1] != 1e18) table[get<0>(nxt)][x+1][1] = min(table[get<0>(nxt)][x+1][1], table[curNode][x][1]+dist[get<0>(nxt)][2-x]);
				}
				
				pq.push({dist[get<0>(nxt)][0], get<0>(nxt)});
			} else if(dist[get<0>(nxt)][0] == cost+get<1>(nxt)){
				for(int x=0;x<3;x++){
					for(int y=0;y<2;y++){
						table[get<0>(nxt)][x][y] = min(table[get<0>(nxt)][x][y], table[curNode][x][y]);
					}
				}
				for(int x=0;x<2;x++){
					if(table[curNode][x][0] != 1e18) table[get<0>(nxt)][x+1][0] = min(table[get<0>(nxt)][x+1][0], table[curNode][x][0]+dist[get<0>(nxt)][x+1]);
					if(table[curNode][x][1] != 1e18) table[get<0>(nxt)][x+1][1] = min(table[get<0>(nxt)][x+1][1], table[curNode][x][1]+dist[get<0>(nxt)][2-x]);
				}
			}
		}
	}
	
	cout << min(min(table[t][2][0], table[t][2][1]), dist[v][1]) << "\n";
	return 0;	
}
