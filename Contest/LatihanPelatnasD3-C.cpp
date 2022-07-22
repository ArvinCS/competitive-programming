#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<pair<int, int>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, l, r;
	cin >> n >> m >> l >> r;
	
	int u[m], v[m], z[m];
	for(int x=0;x<m;x++){
		cin >> u[x] >> v[x] >> z[x];
		
		adj[u[x]].push_back({v[x], z[x]});
		adj[v[x]].push_back({u[x], z[x]});
	}
	
	int dist[n];
	fill(dist, dist+n, 1e9);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[0] = 0;
	pq.push({dist[0], 0});
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > dist[p.second]+nxt.second){
				dist[nxt.first] = dist[p.second]+nxt.second;
				pq.push({dist[nxt.first], nxt.first});
			}
		}
	}
	
	int ans = 0;
	for(int x=0;x<m;x++){
		if(dist[u[x]]*2 < r){
			ans++;
		} else if(dist[v[x]]*2 < r){
			ans++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

