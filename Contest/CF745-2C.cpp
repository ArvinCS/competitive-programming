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

const int infneg = -inf_int;

const int maxN = 405;

int grid[maxN][maxN];
int table[maxN];
int dp[maxN];
int row[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int y=0;y<m;y++) grid[0][y] = (y == 0 || y == m-1);
		for(int x=1;x<=n;x++){
			for(int y=0;y<m;y++){
				char c;
				cin >> c;
				
				grid[x][y] = (c - '0');
			}
		}
		
		for(int x=0;x<=n;x++){
			int sum = 0;
			for(int y=0;y<m;y++){
				sum += grid[x][y];
				row[x][y] = sum;
			}
		}
		
		int ans = inf_int;
		for(int y=1;y<m-1;y++){
			for(int z=y;z<m-1;z++){
				for(int x=0;x<=n-1;x++){
					int sum = row[x][z] - row[x][y-1];
					int sum2 = row[x+1][z] - row[x+1][y-1];
					int sum3 = z-y+1-sum2;
					
					table[x] = sum + (x > 0 ? table[x-1] : 0)+!grid[x][y-1]+!grid[x][z+1];
					dp[x] = max(x > 0 ? dp[x-1] : infneg, table[x]+sum2-sum3+!grid[x+1][y-1]+!grid[x+1][z+1]);
					if(x >= 4 && z-y+1 >= 2) ans = min(ans, sum3+table[x]-dp[x-4]);
//					cout << x << "," << y << "-" << z << " -> " << ans << " " << table[x] << "(" << dp[x] << "," << sum << "," << sum3 << ")\n";
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

