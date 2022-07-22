#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<pair<int, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<m;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		a--; b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	pair<ll, int> dist[n];
	fill(dist[0], dist[n], make_pair(1e18, 1e9));
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	for(int x=0;x<k;x++){
		dist[x] = make_pair(0, x);
		pq.push({dist[x].first, x});
	}
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first].first > p.first+nxt.second){
				dist[nxt.first] = make_pair(p.first+nxt.second, dist[p.second].second);
				pq.push({p.first+nxt.second, nxt.first});
			}
		}
	}
	
	
    return 0;
}

