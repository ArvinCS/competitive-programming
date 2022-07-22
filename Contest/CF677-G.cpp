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

const int maxN = 1e3 + 5;

tuple<int, int, int> edges[maxN];
vector<pair<int, int>> adj[maxN];
int dist[maxN], dist2[maxN][2], cost[maxN];

void solve(int curNode, int i){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist2[curNode][i] = 0;
	pq.push({dist2[curNode][i], curNode});
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(p.first > dist2[p.second][i]) continue;
		
		for(auto nxt : adj[p.second]){
			if(dist2[nxt.first][i] > dist2[p.second][i]+get<2>(edges[nxt.second])){
				dist2[nxt.first][i] = dist2[p.second][i]+get<2>(edges[nxt.second]);
				pq.push({dist2[nxt.first][i], nxt.first});
			}
		}
	}
}

int solve2(int source, int target){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[source] = 0;
	pq.push({dist[source], source});
	
	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		
		if(p.first > dist[p.second]) continue;
		dist[p.second] = p.first;
		if(p.second == target){
			break;
		}
		
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first] > dist[p.second]+get<2>(edges[nxt.second])){
				dist[nxt.first] = dist[p.second]+get<2>(edges[nxt.second]);
				pq.push({dist[nxt.first], nxt.first});
			}
		}
	}
	return dist[target];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<m;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		a--; b--;
		
		edges[x] = make_tuple(a, b, c);
		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	pair<int, int> cour[k];
	for(int x=0;x<k;x++){
		cin >> cour[x].first >> cour[x].second;
		cour[x].first--; cour[x].second--;
	}
	
	ll ans = 0;
	
	for(int x=0;x<k;x++){
		fill(dist, dist+maxN, inf_int);
		cost[x] = solve2(cour[x].first, cour[x].second);
		ans += cost[x];
	}
	
	for(int x=0;x<m;x++){
		ll tmp = 0;
		
		fill(dist2[0], dist2[maxN], inf_int);
		solve(get<0>(edges[x]), 0);
		solve(get<1>(edges[x]), 1);
		
		for(int y=0;y<k;y++){
			tmp += min(cost[y], min(dist2[cour[y].first][0]+dist2[cour[y].second][1], dist2[cour[y].second][0]+dist2[cour[y].first][1]));
		}
		ans = min(ans, tmp);
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

