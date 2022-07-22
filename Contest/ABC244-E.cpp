#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 2e3 + 5;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k, s, t, p;
	cin >> n >> m >> k >> s >> t >> p;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll table[k+2][n+1][2];
	fill(*table[0], *table[k+2], 0);
	
	table[1][s][0] = 1;
	for(int x=1;x<=k;x++){
		for(int y=1;y<=n;y++){
			for(int i=0;i<2;i++){
				for(auto nxt : adj[y]){
					table[x+1][nxt][(i+(nxt==p))%2] += table[x][y][i];
					if(table[x+1][nxt][(i+(nxt==p))%2] >= mod) table[x+1][nxt][(i+(nxt==p))%2] -= mod;
				}
			}
		}
	}
	
	cout << table[k+1][t][0] << "\n";
    return 0;
}

