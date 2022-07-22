#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<pair<int, int>> tree[20][maxN];
vector<int> v[20][2];
ll dist[20][2][maxN];

int main(){
	int n, m, d;
	cin >> n >> m >> d;
	
	for(int x=0;x<m;x++){
		int u, v, w, t;
		cin >> u >> v >> w >> t;
		
		u--; v--;
		for(int i=0;i<17;i++){
			int bit = (1 << i);
			if(t&bit){
				tree[i][u].push_back({v, w});
				tree[i][v].push_back({u, w});
			}
		}	
	}
	
	int p[d], a[d];
	for(int x=0;x<d;x++){
		cin >> p[x] >> a[x];
		p[x]--;
		
		for(int i=0;i<17;i++){
			int bit = (1 << i);
			
			if(a[x]&bit){
				v[i][1].push_back(p[x]);
			} else {
				v[i][0].push_back(p[x]);
			}
		}
	}
	
	fill(*dist[0], *dist[20], 1e18);
	
	for(int i=0;i<17;i++){
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		for(int j=0;j<2;j++){
			for(auto node : v[i][j]){
				dist[i][j][node] = 0;
				pq.push({dist[i][j][node], node});
			}
			
			while(!pq.empty()){
				pair<ll, int> p = pq.top();
				pq.pop();
				
				if(dist[i][j][p.second] < p.first) continue;
				for(auto nxt : tree[i][p.second]){
					if(dist[i][j][nxt.first] > p.first+nxt.second){
						dist[i][j][nxt.first] = p.first+nxt.second;
						pq.push({dist[i][j][nxt.first], nxt.first});
					}
				}
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<d;x++){
		ll best = 1e18;
		for(int i=0;i<17;i++){
			int bit = (1 << i);
			if(a[x]&bit){
				best = min(best, dist[i][0][p[x]]);
			} else {
				best = min(best, dist[i][1][p[x]]);
			}
		}

		if(best >= 1e18){
			cout << "-1\n";
			return 0;
		}
		
		ans += best;
	}
	
	cout << ans << "\n";
	return 0;
}
