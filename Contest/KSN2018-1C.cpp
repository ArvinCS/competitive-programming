#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 105;

vector<pair<int, int>> adj[maxN];
ll k[maxN*maxN];
int q[maxN*maxN];
ll dist[maxN][maxN*maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string subsoal;
	cin >> subsoal;
	
	int n, m;
	cin >> n >> m;
	
	ll cd, md, cp, mp;
	cin >> cd >> md;
	cin >> cp >> mp;
	
	int a, b;
	cin >> a >> b;
	a--; b--;
	
	for(int x=0;x<m;x++){
		int u, v;
		cin >> u >> v >> k[x] >> q[x];
		
		u--; v--;
		adj[u].push_back({v, x});
		adj[v].push_back({u, x});
	}
	
	fill(dist[0], dist[maxN], 1e18);
	
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
	dist[a][0] = 0;
	pq.push(make_tuple(dist[a][0], 0, a));
	
	while(!pq.empty()){
		tuple<ll, int, int> t = pq.top();
		pq.pop();
		
		int curNode = get<2>(t), rem = get<1>(t);
		ll curDist = get<0>(t);
		
		if(dist[curNode][rem] < curDist) continue;
		
//		cout << curNode << " " << rem << " -> " << curDist << "\n";
		for(auto nxt : adj[curNode]){
			ll need = (max(0ll, k[nxt.second]-rem)+mp-1)/mp;
			ll rem2 = max(0ll, rem-k[nxt.second]) + ((mp - (max(0ll, k[nxt.second]-rem) % mp)) % mp);
			
			if(dist[nxt.first][rem2] > curDist+need*cp){
				dist[nxt.first][rem2] = curDist+need*cp;
//				cout << " = " << nxt.first << " " << rem2 << " " << curDist+need*cp << "\n";
				pq.push(make_tuple(dist[nxt.first][rem2], rem2, nxt.first));
			}
			
			if(need > 0 && !q[nxt.second]){
				need--;
				rem2 = 0;
				
				if(dist[nxt.first][rem2] > curDist+need*cp+max(0ll, k[nxt.second]-rem-need*mp)*cd){
					dist[nxt.first][rem2] = curDist+need*cp+max(0ll, k[nxt.second]-rem-need*mp)*cd;
					pq.push(make_tuple(dist[nxt.first][rem2], rem2, nxt.first));
				}
				
				if(need > 1){
					need = 1;
					if(dist[nxt.first][rem2] > curDist+need*cp+max(0ll, k[nxt.second]-rem-need*mp)*cd){
						dist[nxt.first][rem2] = curDist+need*cp+max(0ll, k[nxt.second]-rem-need*mp)*cd;
						pq.push(make_tuple(dist[nxt.first][rem2], rem2, nxt.first));
					}
				}
			}
			
			rem2 = rem;
			if(q[nxt.second]){
				if(rem2 < k[nxt.second]) rem2 = 0;
			}
			
			need = (max(0ll, k[nxt.second]-rem2)+md-1) / md;
			
//			cout << curNode << " " << nxt.first << " " << need << " " << rem2 << " " << curDist << "\n";
			for(int y=0;y<=md;y++){
				if(dist[curNode][y] > curDist+y*cd){
					dist[curNode][y] = curDist+y*cd;
					pq.push(make_tuple(dist[curNode][y], y, curNode));
				}
			}
			
			if(!q[nxt.second] || need <= 1){
				ll bound = (md - max(0ll, k[nxt.second]-rem2) % md) % md;
				for(int y=0;y<=bound;y++){
					ll rem3 = max(0ll, rem2-k[nxt.second])+y;
	//				cout << curNode << " " << rem3 << " " << nxt.first << " " << bound << "\n";
					
					if(dist[nxt.first][rem3] > curDist+(max(0ll, k[nxt.second]-rem2) + y)*cd){
						dist[nxt.first][rem3] = curDist+(max(0ll, k[nxt.second]-rem2) + y)*cd;
						pq.push(make_tuple(dist[nxt.first][rem3], rem3, nxt.first));
					}
				}
			}
		}
	}
	
	ll ans = 2e18;
	for(int x=0;x<maxN*maxN;x++){
		ans = min(ans, dist[b][x]);
	}
	cout << ans << "\n";
	return 0;
}

