#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	int from, to, energy;
	cin >> from >> to >> energy;
	
	vector<pair<ll, ll>> adj[n+1];
	for(int x=1;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	bool visited[n+1];
	ll dist[n+1];
		
	ll left = 0, right = 1e9, ans = -1;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		
		fill(visited, visited+n+1, false);
		fill(dist, dist+n+1, inf_ll);
		
		queue<pair<ll, ll>> q;
		q.push({0, from});
		dist[from] = 0;
		
		while(!q.empty()){
			pair<ll, ll> p = q.front();
			q.pop();
			
			if(!visited[p.second]){
				visited[p.second] = true;
				for(auto nxt : adj[p.second]){
					if(nxt.second < mid && dist[nxt.first] > nxt.second && !visited[nxt.first]){
						dist[nxt.first] = nxt.second;
						q.push({dist[nxt.first], nxt.first});
					}
				}
			}
		}
		
		if(!visited[from] || !visited[to]){
			left = mid+1;
			ans = mid;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
