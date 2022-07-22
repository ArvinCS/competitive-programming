#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 2e5 + 5;

vector<int> adj[maxN][2];
ll pw[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = (2ll * pw[x-1]) % mod;
	}
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a][0].push_back(b);
		adj[b][1].push_back(a);
	}
	
	int dist[n][21];
	fill(dist[0], dist[n], 1e9);
	
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
	dist[0][0] = 0;
	pq.push({0, 0, 0});
	
	while(!pq.empty()){
		array<int, 3> a = pq.top();
		pq.pop();
		
		int len = a[0];
		int level = a[1];
		int idx = a[2];
		
		if(dist[idx][level] < len) continue;
		
		bool odd = (level % 2 == 1);
		if(!adj[idx][odd].empty()){
			for(auto nxt : adj[idx][odd]){
				if(dist[nxt][level] > len+1){
					dist[nxt][level] = len+1;
					pq.push({len+1, level, nxt});
				}
			}
		}
		
		if(level < 20 && dist[idx][level+1] > len+pw[level]){
			dist[idx][level+1] = len+pw[level];
			pq.push({len+pw[level], level+1, idx});
		}
	}
	
	pair<int, int> dist2[n][2];
	fill(dist2[0], dist2[n], make_pair(1e9, 1e9));
	
	for(int x=0;x<n;x++){
		for(int y=1;y<21;y++){
			dist[x][y] = min(dist[x][y] * 1ll, dist[x][y-1]+pw[y-1]);
		}
		
		if(dist[x][20] != 1e9){
			dist2[x][0] = {20, dist[x][20]};
			pq.push({20, dist[x][20], x});
		}
	}
	
	while(!pq.empty()){
		array<int, 3> cur = pq.top();
		pq.pop();
		
		int idx = cur[2];
		int level = cur[0];
		int dist = cur[1];
		
		bool odd = (level % 2 == 1);
		
		if(dist2[idx][odd] < make_pair(level, dist)) continue;
		
		if(!adj[idx][odd].empty()){
			for(auto nxt : adj[idx][odd]){
				if(dist2[nxt][odd] > make_pair(level, dist+1)){
					dist2[nxt][odd] = {level, dist+1};
					pq.push({level, dist+1, nxt});
				}
			}
		}
		
		if(dist2[idx][odd^1] > make_pair(level+1, dist)){
			dist2[idx][odd^1] = make_pair(level+1, dist);
			pq.push({level+1, dist, idx});
		}
	}
	
	ll ans = 1e18;
	for(int x=0;x<21;x++){
		if(dist[n-1][x] != 1e9) ans = min(ans, dist[n-1][x]*1ll);
	}
	
	if(ans == 1e18){
		if(dist2[n-1][0].first < dist2[n-1][1].first){
			ans = (dist2[n-1][0].second + (pw[dist2[n-1][0].first]-1+mod) % mod - (pw[20]-1+mod) % mod + mod) % mod;
		} else {
			ans = (dist2[n-1][1].second + (pw[dist2[n-1][1].first]-1+mod) % mod - (pw[20]-1+mod) % mod + mod) % mod;
		}
	}
	
	cout << ans % mod << "\n";
    return 0;
}

