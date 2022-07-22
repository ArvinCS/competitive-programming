#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const ll mod = 1e9 + 7;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		int s, t;
		cin >> s >> t;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		s--; t--;
		
		queue<int> q[2];
		q[0].push(s);
		
		int dist[n][2];
		ll table[n][2];
		fill(table[0], table[n], 0);
		fill(dist[0], dist[n], -1);
		
		table[s][0] = 1;
		dist[s][0] = 0;
		
		while(!q[0].empty()){
			int curNode = q[0].front();
			q[0].pop();
			
			for(auto nxt : adj[curNode]){
				if(dist[nxt][0] == -1){
					dist[nxt][0] = dist[curNode][0]+1;
					table[nxt][0] += table[curNode][0];
					if(table[nxt][0] >= mod) table[nxt][0] -= mod;
					
					q[0].push(nxt);
				} else if(dist[nxt][0] == dist[curNode][0]+1){
					table[nxt][0] += table[curNode][0];
					if(table[nxt][0] >= mod) table[nxt][0] -= mod;
				}
			}
		}
		
		dist[t][1] = 0;
		table[t][1] = 1;
		q[1].push(t);
		while(!q[1].empty()){
			int curNode = q[1].front();
			q[1].pop();
			
			for(auto nxt : adj[curNode]){
				if(dist[nxt][1] == -1){
					dist[nxt][1] = dist[curNode][1]+1;
					table[nxt][1] += table[curNode][1];
					if(table[nxt][1] >= mod) table[nxt][1] -= mod;
					
					q[1].push(nxt);
				} else if(dist[nxt][1] == dist[curNode][1]+1){
					table[nxt][1] += table[curNode][1];
					if(table[nxt][1] >= mod) table[nxt][1] -= mod;
				}
			}
		}
		
		ll ans = table[t][0];
		
		for(int x=0;x<n;x++){
			for(auto nxt : adj[x]){
				if(dist[nxt][0] == dist[x][0] && (dist[nxt][1]+dist[x][0]) == dist[t][0]){
					ans += (table[nxt][1]*table[x][0]) % mod;
//					cout << x << " " << nxt << " -> " << table[nxt][1] << " " << table[x][0] << "\n";
					if(ans >= mod) ans -= mod;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

