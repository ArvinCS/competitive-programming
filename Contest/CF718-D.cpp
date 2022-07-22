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

const int maxN = 3e5;

vector<pair<int, ll>> adj[maxN];
ll table[25][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m-1;y++){
			int a = (x*m)+y, b = (x*m)+y+1;
			ll cost;
			cin >> cost;
			
			adj[a].push_back({b, cost});
			adj[b].push_back({a, cost});
		}
	}
	for(int x=0;x<n-1;x++){
		for(int y=0;y<m;y++){
			int a = (x*m)+y, b = ((x+1)*m)+y;
			ll cost;
			cin >> cost;
			
			adj[a].push_back({b, cost});
			adj[b].push_back({a, cost});
		}
	}
	
	ll ans[n][m];
	fill(ans[0], ans[n], -1);
	
	if(k%2 == 0){
		fill(table[0], table[25], inf_ll);
		for(int x=0;x<maxN;x++) table[0][x] = 0;
		
		for(int i=1;i<=k;i++){ // dp
			for(int x=0;x<n*m;x++){
				ll best = inf_ll;
				for(auto nxt : adj[x]){
					best = min(best, nxt.second+table[i-1][nxt.first]);
				}
				table[i][x] = best;
			}
		}
		
		for(int x=0;x<n*m;x++){ // translate to grid
			int row = x/m, col = x%m;
			ans[row][col] = 2ll*table[k/2][x];
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(y > 0) cout << " ";
			cout << ans[x][y];
		}
		cout << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

