#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e3 + 5;

vector<pair<int, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, e, k;
	cin >> n >> e >> k;
	
	int c[k];
	for(int x=0;x<k;x++){
		cin >> c[x];
	}
	
	for(int x=0;x<e;x++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		
		c /= 10;
		adj[b].push_back({a, c});
	}
	
	int fullstate = (1 << 5);
	ll dist[n][fullstate];
	fill(dist[0], dist[n], 1e18);
	
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
	for(int x=0;x<k;x++){
		dist[c[x]][0] = 0;
		pq.push({0, 0, c[x]});
	}
	
	while(!pq.empty()){
		array<ll, 3> a = pq.top();
		pq.pop();
		
		ll d = a[0];
		int state = a[1];
		int curNode = a[2];
		
		if(dist[curNode][state] < d) continue;
				
		for(auto nxt : adj[curNode]){
			for(int y=-1;y<5;y++){
				int bit = (y == -1 ? 0 : (1 << y));
				if(!(state&bit)){
					if(dist[nxt.first][state|bit] > d+nxt.second*(y == -1 ? 10 : 9-y)){
						dist[nxt.first][state|bit] = d+nxt.second*(y == -1 ? 10 : 9-y);
						pq.push({dist[nxt.first][state|bit], state|bit, nxt.first});
					}
				}
			}
		}
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int node;
		cin >> node;
		
		ll cost[5];
		for(int x=0;x<5;x++){
			cin >> cost[x];	
		}
		
		ll ans = 1e18;
		for(int state=0;state<fullstate;state++){
			bool valid = true;
			ll val = 0;
			for(int y=0;y<5;y++){
				if(cost[y] == -1 && (state&(1 << y))){
					valid = false;
				}
				if(state&(1 << y)) val += cost[y];
			}
			if(!valid) continue;
			
			ans = min(ans, val+dist[node][state]);
		}
		if(ans == 1e18) ans = -1;
		cout << ans << "\n";
	}
	return 0;
}
