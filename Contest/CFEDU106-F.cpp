#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e3 + 5;
const ll mod = 998244353;

vector<int> adj[maxN];
ll table[maxN][maxN];
ll new_dp[maxN];

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

void dfs(int curNode, int prvNode, int k){
	table[curNode][0] = 1;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode, k);
			
			fill(new_dp, new_dp+k+1, 0);
			
			// distprv <= k-distcur
			// 0 -> k
			// 1 -> k-1
			// 2 -> k-2
			// 3 -> k-3
			// 4 -> k-4
			
			for(int y=1;y<=k;y++){
				chadd(table[curNode][y], table[curNode][y-1]);
			}
			for(int y=0;y<=k;y++){
				chadd(new_dp[y], table[nxt][y]*table[curNode][min(k-y, y)] % mod);
			}
			
			for(int y=k;y>=1;y--){
				chadd(table[curNode][y], -table[curNode][y-1]);
			}
			for(int y=1;y<=k;y++){
				chadd(table[nxt][y], table[nxt][y-1]);
			}
			
			for(int y=1;y<=k;y++){
				chadd(new_dp[y], table[curNode][y]*table[nxt][min(k-y, y-1)] % mod);
			}
			
			for(int y=k;y>=1;y--){
				chadd(table[nxt][y], -table[nxt][y-1]);
			}
			
			for(int y=0;y<=k;y++){
				table[curNode][y] = new_dp[y];
			}
		}
	}
	
	if(curNode != 0){
		ll sum = 0;
		for(int y=k;y>=0;y--){
			chadd(sum, table[curNode][y]);
			if(y > 0) table[curNode][y] = table[curNode][y-1];
		}
		table[curNode][0] = sum;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(0, -1, k);
	
	ll ans = 0;
	for(int y=0;y<=k;y++){
		chadd(ans, table[0][y]);
	}
	
	cout << ans << "\n";
    return 0;
}

