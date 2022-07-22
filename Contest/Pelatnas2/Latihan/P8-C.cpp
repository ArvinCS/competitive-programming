#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 505;
const int maxM = 1505;
const int maxT = 1445;
const int maxG = 245;
const int maxE = 1e4 + 5;
const short inf = 32760;

vector<pair<int, short>> adj[maxN];
short cost[maxM][maxT];
short dist[maxN][maxT][maxG];
bool done[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, t, g;
	cin >> n >> m >> t >> g;
	
	for(int x=0;x<m;x++){
		int u, v;
		cin >> u >> v;
		
		cost[x][0] = -1;
		while(true){
			int l, r;
			short c;
			cin >> l >> r >> c;
			
			for(int y=l;y<=r;y++){
				cost[x][y] = c;
			}
			if(r == t-1){
				break;
			}
		}
		
		adj[u].push_back({v, x});
		adj[v].push_back({u, x});
	}
	
	fill(*dist[0], *dist[n], inf);
	fill(done, done+n, false);
	
	priority_queue<array<short, 4>, vector<array<short, 4>>, greater<array<short, 4>>> pq; 
	dist[0][t/2][g] = 0;
	pq.push({dist[0][t/2][g], 0, t/2, g});
	
	while(!pq.empty()){
		array<short, 4> a = pq.top();
		pq.pop();
		
		if(a[1] == n-1){
			cout << a[0] << "\n";
			break;
		}
		if(dist[a[1]][a[2]][a[3]] < a[0]){
			continue;
		}
		
		if(!done[a[1]]){
			done[a[1]] = true;
			for(int i=1;i<max(t, 2*(g-a[3])+1);i++){
				if(dist[a[1]][(a[2]+i)%t][min(g, a[3]+i/2)] > a[0]+i){
					dist[a[1]][(a[2]+i)%t][min(g, a[3]+i/2)] = a[0]+i;
					pq.push({dist[a[1]][(a[2]+i)%t][min(g, a[3]+i/2)], a[1], (a[2]+i)%t, min(g, a[3]+i/2)});
				}
			}
		}
		
		for(auto nxt : adj[a[1]]){
			int nxtNode = nxt.first;
			int need = cost[nxt.second][a[2]];
			if(need != -1 && a[3] >= need && dist[nxtNode][(a[2]+need)%t][a[3]-need] > a[0]+need){
				dist[nxtNode][(a[2]+need)%t][a[3]-need] = a[0]+need;
				pq.push({dist[nxtNode][(a[2]+need)%t][a[3]-need], nxtNode, (a[2]+need)%t, a[3]-need});
			}
		}
	}
    return 0;
}
