#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int maxM = 2e5 + 5;

vector<pair<int, int>> adj[maxM];
ll dist[maxN], cnt[maxM], rem[maxM];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

long long smaltisci(int n, int m, vector<int> a, vector<vector<int>> b) {
	fill(dist, dist+n, 1e18);
	fill(cnt, cnt+m, 1);
	
	for(int x=0;x<m;x++){
		if(b[x].empty() && dist[a[x]] > 1){
			dist[a[x]] = 1;
			pq.push({dist[a[x]], a[x]});
		}
		for(auto nxt : b[x]){
			rem[x]++;
			adj[nxt].push_back({a[x], x});
		}
	}
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(rem[nxt.second] > 0){
				rem[nxt.second]--;
				cnt[nxt.second] += dist[p.second];
				
				if(rem[nxt.second] == 0 && dist[nxt.first] > cnt[nxt.second]){
					dist[nxt.first] = cnt[nxt.second];
					pq.push({dist[nxt.first], nxt.first});
				}
			}
		}
	}
	
//	for(int x=0;x<n;x++){
//		cout << dist[x] << " ";
//	}cout << "\n";
	return dist[0];	
}
