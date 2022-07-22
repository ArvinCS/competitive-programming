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

const int maxN = 2e5 + 15;

bool visited[maxN], done[maxN];
ll dist[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll n, k;
		cin >> n >> k;
		
		map<ll, vector<ll>> mp;
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			mp[data[x]].push_back(x);
		}
		
		vector<pair<ll, ll>> adj[n+1];
		for(int x=1;x<n;x++){
			adj[x].push_back({x+1, k});
			adj[x+1].push_back({x, k});
		}
		
		fill(done, done+n+5, false);
		
		for(auto m : mp){
			if(m.first >= k) break;
			
			ll cur = m.first;
			for(auto idx : m.second){
				int left = idx, right = idx;
				while(left-1 >= 0 && !done[left] && data[left-1]%m.first == 0){
					left--;
				}
				while(right+1 < n && !done[right] && data[right+1]%m.first == 0){
					right++;
				}
				for(int x=left;x<right;x++){
					done[x] = true;
					adj[x+1].push_back({x+2, m.first});
					adj[x+2].push_back({x+1, m.first});
				}
				done[right] = true;
			}
		}
		
		fill(visited, visited+n+5, false);
		fill(dist, dist+n+5, inf_ll);
		
		ll ans = 0;
		
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
		pq.push({0, 1}); // dist, node
		dist[1] = 0;
		
		while(!pq.empty()){
			pair<ll, ll> p = pq.top();
			pq.pop();
			
			if(!visited[p.second]){
				visited[p.second] = true;
				ans += dist[p.second];
				
				for(auto nxt : adj[p.second]){
					if(dist[nxt.first] > nxt.second && !visited[nxt.first]){
						dist[nxt.first] = nxt.second;
						pq.push({dist[nxt.first], nxt.first});
					}
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

