#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 18;

vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int fullstate = (1 << n);
	int table[n][fullstate];
	fill(table[0], table[n], 1e9);
		
	for(int x=0;x<n;x++){
		table[x][(1 << x)] = 1;
	}
	for(int x=0;x<2*n;x++){
		for(int y=0;y<n;y++){
			for(int state=0;state<fullstate;state++){
				for(auto nxt : adj[y]){
					int bit = (1 << nxt);
					table[nxt][state^bit] = min(table[nxt][state^bit], table[y][state]+1);
				}
			}
		}
	}
	
	ll ans = 0;
	for(int state=1;state<fullstate;state++){
		int mn = 1e9;
		for(int x=0;x<n;x++){
			mn = min(mn, table[x][state]);
		}
		ans += mn;
	}
	
	cout << ans << "\n";
    return 0;
}

