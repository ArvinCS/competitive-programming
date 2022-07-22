#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

vector<pair<int, ll>> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	map<pair<int, int>, int> w;
	ll c[n-1];
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b >> c[x];
		
		a--; b--;
		w[{a, b}] = x;
		w[{b, a}] = x;
		adj[b].push_back({a, x});
		adj[a].push_back({b, x});
	}
	
	int sz = sqrt(n)+1;
	
	vector<pair<int, int>> pending;
	set<int> grape;
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	ll ans[q], dist[n];
	fill(ans, ans+q, -2);
	
	auto dijkstra = [&](ll dist[]) -> void {
		fill(dist, dist+n, 1e18);
		
		for(auto curNode : grape){
			dist[curNode] = 0;
			pq.push({0, curNode});
		}
		
		while(!pq.empty()){
			pair<ll, int> p = pq.top();
			pq.pop();
			
			if(dist[p.second] < p.first) continue;
			for(auto nxt : adj[p.second]){
				if(dist[nxt.first] > p.first+c[nxt.second]){
					dist[nxt.first] = p.first+c[nxt.second];
					pq.push({dist[nxt.first], nxt.first});
				}
			}
		}
	};
	
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int node;
			cin >> node;
			
			node--;
			
			if(grape.count(node)){
				ans[i] = 0;
				continue;
			}
			
			pending.push_back({node, i});
			
			if(pending.size() >= sz){
				dijkstra(dist);
				
				while(!pending.empty()){
					ll val = dist[pending.back().first];
					if(val == 1e18) val = -1;
					
					ans[pending.back().second] = val;
					pending.pop_back();
				}
			}
		} else if(t == 2){
			int node;
			cin >> node;
			
			if(!pending.empty()){
				dijkstra(dist);
				
				while(!pending.empty()){
					ll val = dist[pending.back().first];
					if(val == 1e18) val = -1;
					
					ans[pending.back().second] = val;
					pending.pop_back();
				}
			}
			
			node--;
			auto it = grape.find(node);
			if(it != grape.end()){
				grape.erase(it);
			} else {
				grape.insert(node);
			}
		} else if(t == 3){
			int a, b;
			ll d;
			cin >> a >> b >> d;
			
			if(!pending.empty()){
				dijkstra(dist);
				
				while(!pending.empty()){
					ll val = dist[pending.back().first];
					if(val == 1e18) val = -1;
					
					ans[pending.back().second] = val;
					pending.pop_back();
				}
			}
			
			a--; b--;
			int idx = w[{a, b}];
			
			c[idx] = d;
		}
	}
	if(!pending.empty()){
		dijkstra(dist);
		
		while(!pending.empty()){
			ll val = dist[pending.back().first];
			if(val == 1e18) val = -1;
			
			ans[pending.back().second] = val;
			pending.pop_back();
		}
	}
			
	for(int x=0;x<q;x++){
		if(ans[x] == -2) continue;
		cout << ans[x] << "\n";
	}
	return 0;
}
