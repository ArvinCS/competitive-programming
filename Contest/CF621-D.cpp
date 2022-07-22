#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 10;

vector<int> adj[maxN];

void bfs(int start, ll dist[], bool special){
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	
	while(!q.empty()){
		int curNode = q.front();
		q.pop();
		
		for(auto nxt : adj[curNode]){
			if(dist[nxt] == -1){
				dist[nxt] = dist[curNode]+1;
				q.push(nxt);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<ll, int>> v;
	bool special[n];
	fill(special, special+n, false);
	
	for(int x=0;x<k;x++){
		int idx;
		cin >> idx;
		
		idx--;
		special[idx] = true;
		v.push_back({-1, idx});
	}
	
	bool bothSpecial = false;
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		
		if(special[a] && special[b]) bothSpecial = true;
	}
	
	ll dist[2][n];
	fill(dist[0], dist[2], -1);
	
	bfs(n-1, dist[0], special);
	bfs(0, dist[1], special);
	
	if(bothSpecial){
		cout << dist[0][0] << "\n";
	} else {
		for(int x=0;x<v.size();x++){
			v[x].first = dist[1][v[x].second]-dist[0][v[x].second];
		}
		
		sort(v.begin(), v.end());
		
		ll best = 0, mx = -1e18;
		for(int x=0;x<k;x++){
			best = max(best, mx+dist[0][v[x].second]);
			mx = max(mx, dist[1][v[x].second]);
		}
		
		cout << min(dist[0][0], best+1) << "\n";
	}
    return 0;
}
