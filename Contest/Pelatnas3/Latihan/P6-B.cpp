#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<array<int, 3>> v[n];
	vector<pair<int, int>> adj[n];
	for(int x=0;x<k;x++){
		int m, p, l, r;
		cin >> m >> p >> l >> r;
		
		l--; r--;
		m--;
		for(int y=l;y<=r;y++){
			adj[y].push_back({m, p});
		}
		v[m].push_back({l, r, p});
	}
	
	auto dijkstra = [&](int curNode, ll dist[]){
		fill(dist, dist+n, 1e18);
		
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[curNode] = 0;
		pq.push({dist[curNode], curNode});
		
		while(!pq.empty()){
			pair<ll, int> p = pq.top();
			pq.pop();
			
			if(dist[p.second] < p.first) continue;
			for(auto nxt : adj[p.second]){
				if(dist[nxt.first] > dist[p.second]+nxt.second){
					dist[nxt.first] = dist[p.second]+nxt.second;
					pq.push({dist[nxt.first], nxt.first});
				}
			}
		}
	};
	
	ll distS[n], distT[n];
	dijkstra(0, distS);
	dijkstra(n-1, distT);
	
	ll ans[n];
	fill(ans, ans+n, 1e18);
	
	for(int x=0;x<n;x++){
//		cout << distS[x] << " " << distT[x] << "\n";
		ll distCur[n];
		dijkstra(x, distCur);
		
		for(int y=0;y<n;y++){
			if(distS[x] != 1e18 && distT[x] != 1e18 && distCur[y] != 1e18){
				ans[y] = min(ans[y], distS[x]+distT[x]+distCur[y]);
			}
		}
		if(distT[0] != 1e18 && distS[x] != 1e18){
			ans[x] = min(ans[x], distS[x]+distT[0]);
		}
		if(distS[n-1] != 1e18 && distT[0] != 1e18){
			ans[x] = min(ans[x], distT[0]+distS[n-1]);
		}
		for(auto a : v[x]){
			if(a[0] == 0 && a[1] == n-1){
				ans[x] = min(ans[x], a[2] * 1ll);
			}
		}
	}
	
	for(int x=0;x<n;x++){
		cout << (ans[x] != 1e18 ? ans[x] : -1) << "\n";
	}
    return 0;
}

