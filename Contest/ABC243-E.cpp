#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<int, ll>> adj[305];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		ll a, b, c;
		cin >> a >> b >> c;
		
		a--; b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	bool mark[n][n], visited[n];
	fill(mark[0], mark[n], false);
	fill(visited, visited+n, false);
	
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
	pair<ll, ll> dist[n];
	int backtrack[n];
	
	ll ans = m;
	for(int x=0;x<n;x++){
	    fill(visited, visited+n, false);
		fill(dist, dist+n, make_pair(1e18, 1e18));
		
		dist[x] = {0, 0};
		pq.push({0, 0, x});
		while(!pq.empty()){
			ll cost = pq.top()[0], used = pq.top()[1], idx = pq.top()[2];
			pq.pop();
			
			if(dist[idx] < make_pair(cost, used)) continue;
			for(auto nxt : adj[idx]){
				if(dist[nxt.first] > make_pair(cost+nxt.second, used+!mark[idx][nxt.first])){
					dist[nxt.first] = make_pair(cost+nxt.second, used+!mark[idx][nxt.first]);
					backtrack[nxt.first] = idx;
					pq.push({dist[nxt.first].first, dist[nxt.first].second, nxt.first});
				}
			}
		}
		
		ll mx = 1e9;
		for(int y=0;y<n;y++){
			if(dist[y].second > 0){
				mx = min(mx, dist[y].second);
			}
		}
		
		for(int y=0;y<n;y++){
			if(dist[y].second == mx){
			    int best = y;
    			while(best != x){
    			    if(!mark[best][backtrack[best]]) ans--;
    				mark[best][backtrack[best]] = true;
    				mark[backtrack[best]][best] = true;
    				visited[best] = true;
    				best = backtrack[best];
    			}
    			visited[best] = true;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}
