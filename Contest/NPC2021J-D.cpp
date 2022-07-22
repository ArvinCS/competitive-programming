#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

vector<pair<int, int>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	
	a--; b--;
	for(int x=0;x<m;x++){
		int u, v, w;
		cin >> u >> v >> w;
		
		u--; v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	int dist[n], dist2[n], cnt[n], cnt2[n];
	fill(dist, dist+n, 1e9);
	fill(dist2, dist2+n, 1e9);
	fill(cnt, cnt+n, 0);
	fill(cnt2, cnt2+n, 0);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[a] = 0;
	cnt[a] = 1;
	pq.push({dist[a], a});
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > p.first+nxt.second){
				dist[nxt.first] = p.first+nxt.second;
				cnt[nxt.first] = cnt[p.second];
				pq.push({dist[nxt.first], nxt.first});
			} else if(dist[nxt.first] == p.first+nxt.second){
				cnt[nxt.first] += cnt[p.second];
			}
		}
	}
	
	dist2[b] = 0;
	cnt2[b] = 1;
	pq.push({dist2[b], b});
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(dist2[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist2[nxt.first] > p.first+nxt.second){
				dist2[nxt.first] = p.first+nxt.second;
				cnt2[nxt.first] = cnt2[p.second];
				pq.push({dist2[nxt.first], nxt.first});
			} else if(dist2[nxt.first] == p.first+nxt.second){
				cnt2[nxt.first] += cnt2[p.second];
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(dist[x]+dist2[x] == dist[b]){
			cout << fixed << setprecision(6) << 2*(cnt[x]*cnt2[x])*1.0/cnt[b] << "\n";
		} else {
			cout << fixed << setprecision(6) << 0 << "\n";
		}
	}
    return 0;
}

