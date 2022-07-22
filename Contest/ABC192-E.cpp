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
	
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	
	a--; b--;
	
	vector<tuple<ll, ll, ll>> adj[n];
	for(ll x=0;x<m;x++){
		ll from, to, time, start;
		cin >> from >> to >> time >> start;
		
		from--; to--;
		adj[from].push_back(make_tuple(to, time, start));
		adj[to].push_back(make_tuple(from, time, start));
	}
	
	ll dist[n];
	fill(dist, dist+n, inf_ll);
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push(make_pair(0, a));
	dist[a] = 0;
	
	while(!pq.empty()){
		pair<ll, ll> p = pq.top();
		pq.pop();
		
		for(auto v : adj[p.second]){
			ll to = get<0>(v), time = get<1>(v), start = get<2>(v);
			
			ll weight = (p.first+start-1)/start * start - p.first + time;
			if(dist[to] > p.first + weight){
				dist[to] = p.first + weight;
				pq.push(make_pair(dist[to], to));
			}
		}
	}
	
	if(dist[b] >= inf_ll) cout << "-1\n";
	else cout << dist[b] << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

