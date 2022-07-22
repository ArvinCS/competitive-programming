#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxK = 305;
const int maxN = 305;
const int maxM = 7e4;

vector<int> adj[maxN][maxN];
ll dp[maxN][maxN], new_dp[maxN][maxN];
int dist[maxN][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int k;
	cin >> k;
	
	int n[k];
	for(int x=0;x<k;x++){
		cin >> n[x];
	}	
	
	int m;
	cin >> m;
	
	for(int x=0;x<m;x++){
	    int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		
		adj[a][b].push_back(c);
		adj[a][c].push_back(b);
	}
	
	fill(dp[0], dp[maxN], 0);
	
	dp[0][0] = 1;
	for(int x=0;x<k;x++){
// 	    for(int y=0;y<=n[x];y++){
// 			adj[y].clear();
// 		}
// 		for(int y=0;y<edge[x].size();y++){
// 			adj[edge[x][y].first].push_back(edge[x][y].second);
// 			adj[edge[x][y].second].push_back(edge[x][y].first);
// 		}
		
	    fill(dist[0], dist[maxN], maxN-1);
	    
		queue<pair<int, int>> q;
		dist[0][0] = 0;
		q.push({dist[0][0], 0});
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			if(dist[p.second][p.first&1] < p.first) continue;
			for(auto nxt : adj[x][p.second]){
				if(dist[nxt][(p.first&1)^1] > p.first+1){
					dist[nxt][(p.first&1)^1] = p.first+1;
					q.push({dist[nxt][(p.first&1)^1], nxt});
				}
			}
		}
		
		fill(new_dp[0], new_dp[maxN], 0);
		for(int even=0;even<maxN;even++){
			for(int odd=0;odd<maxN;odd++){
				for(int y=0;y<n[x];y++){
					new_dp[max(even, dist[y][0])][max(odd, dist[y][1])] += dp[even][odd];
					new_dp[max(even, dist[y][0])][max(odd, dist[y][1])] %= mod;
				}
			}
		}
		swap(dp, new_dp);
	}
	
	ll ans = 0;
	for(int even=0;even<maxN;even++){
		for(int odd=0;odd<maxN;odd++){
			if(min(even, odd) >= maxN-1) continue;
			
			ans += min(even, odd) * dp[even][odd] % mod;
			ans %= mod;
		}
	}

	cout << ans << "\n";
	return 0;
}
