#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll add(ll a, ll b){
	ll val = a+b;
	if(val >= mod) val -= mod;
	return val;
}

ll sub(ll a, ll b){
	ll val = a-b;
	if(val < 0) val += mod;
	return val;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	char grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y];
		}
	}
	
	ll table[n][n][2][2]; // [left][right][left expanding or shrinking][right expanding or shrinking]
	ll new_table[n][n][2][2];
	ll prefix[n][n][2][2];
	fill(**table[0], **table[n], 0);
	
	ll ans = 0;
	for(int x=0;x<n;x++){ // row
		fill(**new_table[0], **new_table[n], 0);
		
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				if(grid[x][r] == '0') break;
				
				new_table[l][r][0][0] += table[l][r][0][0];
				new_table[l][r][0][0]++;
				new_table[l][r][0][0] %= mod;
				
				new_table[l][r][0][1] += ((table[l][n-1][0][0] - table[l][r][0][0] + mod) % mod - (r+1 < n ? table[r+1][n-1][0][0] : 0ll) + mod) % mod;
				new_table[l][r][0][1] += ((table[l][n-1][0][1] - (r > 0 ? table[l][r-1][0][1] : 0) + mod) % mod - (r+1 < n ? table[r+1][n-1][0][1] : 0) + mod) % mod;
				new_table[l][r][0][1] %= mod;
				
				new_table[l][r][1][0] += ((table[0][r][0][0] - table[l][r][0][0] + mod) % mod - (l > 0 ? table[0][l-1][0][0] : 0) + mod) % mod;
				new_table[l][r][1][0] += ((table[0][r][1][0] - (l+1 < n ? table[l+1][r][1][0] : 0) + mod) % mod - (l > 0 ? table[0][l-1][1][0] : 0) + mod) % mod;
				new_table[l][r][1][0] %= mod;
				
				new_table[l][r][1][1] += (((table[0][n-1][0][0] - table[0][r][0][0] + mod) % mod - table[l][n-1][0][0] + mod) % mod + table[l][r][0][0] + mod) % mod;
				new_table[l][r][1][1] += (((table[0][n-1][0][1] - table[l][n-1][0][1] + mod) % mod - (r > 0 ? table[0][r-1][0][1] : 0) + mod) % mod + (r > 0 ? table[l][r-1][0][1] : 0)) % mod;
				new_table[l][r][1][1] += (((table[0][n-1][1][0] - table[0][r][1][0] + mod) % mod - (l+1 < n ? table[l+1][n-1][1][0] : 0) + mod) % mod + (l+1 < n ? table[l+1][r][1][0] : 0)) % mod;
				new_table[l][r][1][1] += (((table[0][n-1][1][1] - (r > 0 ? table[0][r-1][1][1] : 0) + mod) % mod - (l+1 < n ? table[l+1][n-1][1][1] : 0)) % mod + ((l+1 < n && r > 0) ? table[l+1][r-1][1][1] : 0)) % mod;//(table[0][n-1][1][1] - (l+1 < n && r-1 >= 0 ? table[l+1][r-1][1][1] : 0) + mod) % mod;
				new_table[l][r][1][1] %= mod;
			}
		}
		
		fill(**prefix[0], **prefix[n], 0);
		
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				for(int i=0;i<2;i++){
					for(int j=0;j<2;j++){
						prefix[n-1-l][r][i][j] += new_table[l][r][i][j];
						prefix[n-1-l][r][i][j] %= mod;
					}
				}
			}
		}
		
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int x=0;x<n;x++){
					ll sum = 0;
					for(int y=0;y<n;y++){
						sum += prefix[x][y][i][j];
						sum %= mod;
						
						prefix[x][y][i][j] = (x > 0 ? prefix[x-1][y][i][j] : 0) + sum;
						prefix[x][y][i][j] %= mod; 
					}
				}
			}
		}
		
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				for(int i=0;i<2;i++){
					for(int j=0;j<2;j++){
						table[l][r][i][j] = prefix[n-1-l][r][i][j];
					}
				}
			}
		}
		
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				ans += table[0][n-1][i][j];
				ans %= mod;
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}
