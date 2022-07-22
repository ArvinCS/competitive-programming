#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2002;
const ll inf = 1e18;

ll dist[maxN][maxN];
vector<pair<int, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	fill(dist[0], dist[n], 1e18);
	for(int x=0;x<n;x++){
		dist[x][x] = 0;
	}
	for(int x=0;x<m;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		a--; b--;
		dist[a][b] = c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int z=0;z<n;z++){
				dist[x][z] = min(dist[x][z], dist[x][y]+dist[y][z]);
			}
		}
	}
	
	int l;
	cin >> l;
	
	int p[l];
	for(int x=0;x<l;x++){
		cin >> p[x];
		p[x]--;
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		
		a--;
		b--;
		p[a] = b;
		
		ll dp[n];
		fill(dp, dp+n, 0);
		
		ll new_dp[n];
		
		for(int x=0;x+1<l;x++){
			fill(new_dp, new_dp+n, 1e18);
			
			int cur = p[x], nxt = p[x+1];
			
			ll prefix[n], suffix[n];
			for(int x=0;x<adj[cur].size();x++){
				prefix[x] = (x > 0 ? prefix[x-1] : 1e18);
				prefix[x] = min(prefix[x], dp[adj[cur][x].first]);
			}
			for(int x=adj[cur].size()-1;x>=0;x--){
				suffix[x] = (x+1 < adj[cur].size() ? suffix[x+1] : 1e18);
				suffix[x] = min(suffix[x], dp[adj[cur][x].first]);
			}
			
			bool f = (x == 0);
			for(int x=0;x<adj[cur].size();x++){
				auto p1 = adj[cur][x];
				for(auto p3 : adj[p1.first]){
					for(auto p2 : adj[nxt]){
						cout << cur << "-" << nxt << " = " << p1.first << " " << p2.first << " " << min(x > 0 ? prefix[x-1] : inf, x+1 < adj[cur].size() ? suffix[x+1] : inf)+p1.second+dist[p1.first][p2.first]+p2.second << " -\n";
						new_dp[p2.first] = min(new_dp[p2.first], (f ? 0 : min(x > 0 ? prefix[x-1] : inf, x+1 < adj[cur].size() ? suffix[x+1] : inf))+p1.second+p3.second+dist[p3.first][p2.first]+p2.second);
					}
					if(p1.first == nxt){
						new_dp[p1.first] = min(new_dp[p1.first], (f ? 0 : min(x > 0 ? prefix[x-1] : inf, x+1 < adj[cur].size() ? suffix[x+1] : inf))+p1.second);
					}
				}
			}
			for(int x=0;x<n;x++){
				cout << x << " -> " << new_dp[x] << "\n";
				dp[x] = new_dp[x];
			}
		}
		
		ll ans = 1e18;
		for(int x=0;x<n;x++){
			ans = min(ans, dp[x]);
		}
		
		cout << (ans != inf ? ans : -1) << "\n";
	}
    return 0;
}

