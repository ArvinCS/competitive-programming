#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<pair<int, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back({b, (h[a] >= h[b] ? h[a]-h[b] : 2*(h[a]-h[b]))});
		adj[b].push_back({a, (h[b] >= h[a] ? h[b]-h[a] : 2*(h[b]-h[a]))});
	}
	
	ll dist[n];
	fill(dist, dist+n, 1e18);
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[0] = 0;
	pq.push({dist[0], 0});
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > p.first-nxt.second){
				dist[nxt.first] = p.first-nxt.second;
				pq.push({dist[nxt.first], nxt.first});
			}
		}
	}
	
	ll ans = 1e18;
	for(int x=0;x<n;x++){
		ans = min(ans, dist[x]);
	}
	
	cout << -ans << "\n";
    return 0;
}

