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

const int maxN = 2005;

int n, m;
int grid[maxN][maxN];
int dp[maxN][maxN];

int solve(int x, int y, bool first){
	if(x == n-1 && y == m-1) return 0;
	if(dp[x][y] != -inf_int) return dp[x][y];
	
	if(first){
		int a = -inf_int, b = -inf_int;
		if(x+1 < n){
			a = grid[x+1][y] + solve(x+1, y, !first);
		}
		if(y+1 < m){
			b = grid[x][y+1] + solve(x, y+1, !first);
		}
		return dp[x][y] = max(a, b);
	} else {
		int a = inf_int, b = inf_int;
		if(x+1 < n){
			a = -grid[x+1][y] + solve(x+1, y, !first);
		}
		if(y+1 < m){
			b = -grid[x][y+1] + solve(x, y+1, !first);
		}
		return dp[x][y] = min(a, b);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		string s;
		cin >> s;
		
		for(int y=0;y<m;y++){
			grid[x][y] = (s[y] == '+' ? 1 : -1);
		}
	}
	
	for(int x=0;x<maxN;x++){
		for(int y=0;y<maxN;y++){
			dp[x][y] = -inf_int;
		}
	}
//	int dp[n][m];
//	dp[0][0] = 0;
//	for(int x=0;x<n;x++){
//		for(int y=0;y<m;y++){
//			if(x == 0 && y == 0) continue;
//			
//			bool takahashi = (x+y)&1;
//			
//			if(takahashi){
//				dp[x][y] = min(x > 0 ? dp[x-1][y] : inf_int, y > 0 ? dp[x][y-1] : inf_int) + grid[x][y];
//			} else { // aoki turn
//				dp[x][y] = max(x > 0 ? dp[x-1][y] : -inf_int, y > 0 ? dp[x][y-1] : -inf_int) - grid[x][y];
//			}
//		}
//	}
	
	int ans = solve(0, 0, true);
	if(ans > 0){
		cout << "Takahashi\n";
	} else if(ans == 0){
		cout << "Draw\n";
	} else {
		cout << "Aoki\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

