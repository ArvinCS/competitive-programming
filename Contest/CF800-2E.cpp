#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN], rev_adj[maxN];
int dist[maxN];
bool visited[maxN];
int n;

// rough greedy
// this can be solved by reverse dijkstra
// AC
//int dfs(int curNode, int d = 0){
//	visited[curNode] = true;
//	if(curNode == n-1) return d;
//	
//	int cnt = 0;
//	vector<pair<int, int>> w;
//	for(auto nxt : adj[curNode]){
//		if(!visited[nxt]){
//			w.push_back({dist[nxt], nxt});
//		} else {
//			cnt++;
//		}
//	}	
//	
//	sort(w.rbegin(), w.rend());
//	
//	pair<int, int> mn = {1e9, -1};
//	for(int x=0;x<w.size();x++){
//		mn = min(mn, {d+x+1+w[x].first+cnt, x});
//	}
//	
//	assert(mn.second >= 0 && mn.second < n);
//	
//	return dfs(w[mn.second].second, d+cnt+mn.second+1);
//}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		rev_adj[b].push_back(a);
	}
	
	fill(dist, dist+n, 1e9);
	
	int cnt[n];
	for(int x=0;x<n;x++){
		cnt[x] = adj[x].size();
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[n-1] = 0;
	pq.push({dist[n-1], n-1});
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second] < p.first) continue;
		for(auto nxt : rev_adj[p.second]){
			cnt[nxt]--;

			if(dist[nxt] > p.first+1+cnt[nxt]){
				dist[nxt] = p.first+1+cnt[nxt];
				pq.push({dist[nxt], nxt});
			}
		}
	}
	
	cout << dist[0] << "\n";
    return 0;
}

