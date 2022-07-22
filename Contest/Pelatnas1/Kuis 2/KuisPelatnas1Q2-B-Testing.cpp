#include <bits/stdc++.h>



using namespace std;



#define ll long long



const ll mod = 1e9 + 7;



ll add(ll a, ll b){

	return (a + b) % mod;

}



ll sub(ll a, ll b){

	return (a - b + mod) % mod;	

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

				

				new_table[l][r][0][1] += sub(sub(table[l][n-1][0][0], table[l][r][0][0]), (r+1 < n ? table[r+1][n-1][0][0] : 0));

				new_table[l][r][0][1] %= mod;

				new_table[l][r][0][1] += sub(sub(table[l][n-1][0][1], (r > 0 ? table[l][r-1][0][1] : 0)), (r+1 < n ? table[r+1][n-1][0][1] : 0));

				new_table[l][r][0][1] %= mod;

				

				new_table[l][r][1][0] += sub(sub(table[0][r][0][0], table[l][r][0][0]), (l > 0 ? table[0][l-1][0][0] : 0));

				new_table[l][r][1][0] %= mod;

				new_table[l][r][1][0] += sub(sub(table[0][r][1][0], (l+1 < n ? table[l+1][r][1][0] : 0)), (l > 0 ? table[0][l-1][1][0] : 0));

				new_table[l][r][1][0] %= mod;

				

				new_table[l][r][1][1] += add(sub(sub(table[0][n-1][0][0], table[0][r][0][0]), table[l][n-1][0][0]), table[l][r][0][0]);

				new_table[l][r][1][1] %= mod;

				new_table[l][r][1][1] += add(sub(sub(table[0][n-1][0][1], table[l][n-1][0][1]), (r > 0 ? table[0][r-1][0][1] : 0)), (r > 0 ? table[l][r-1][0][1] : 0));

				new_table[l][r][1][1] %= mod;

				new_table[l][r][1][1] += add(sub(sub(table[0][n-1][1][0], table[0][r][1][0]), (l+1 < n ? table[l+1][n-1][1][0] : 0)), (l+1 < n ? table[l+1][r][1][0] : 0));

				new_table[l][r][1][1] %= mod;

				new_table[l][r][1][1] += add(sub(sub(table[0][n-1][1][1], (r > 0 ? table[0][r-1][1][1] : 0)), (l+1 < n ? table[l+1][n-1][1][1] : 0)), ((l+1 < n && r > 0) ? table[l+1][r-1][1][1] : 0));//(table[0][n-1][1][1] - (l+1 < n && r-1 >= 0 ? table[l+1][r-1][1][1] : 0) + mod) % mod;

				new_table[l][r][1][1] %= mod;

			}

		}

		

		fill(**table[0], **table[n], 0);

		

		ll prefix[n][n][2][2];

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


