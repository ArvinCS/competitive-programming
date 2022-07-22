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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		
		bool grid[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				char c;
				cin >> c;
				
				grid[x][y] = (c == '*');
			}
		}
		
		int table[n][m][2];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(grid[x][y] && x > 0 && y > 0){
					table[x][y][0] = 1 + table[x-1][y-1][0];
				} else {
					table[x][y][0] = grid[x][y];
				}
			}
			
			for(int y=m-1;y>=0;y--){
				if(grid[x][y] && x > 0 && y < m-1){
					table[x][y][1] = 1 + table[x-1][y+1][1];
				} else {
					table[x][y][1] = grid[x][y];
				}
			}
		}
		
		bool possible = true;
		bool must[n][m];
		fill(must[0], must[n], true);
		
		for(int x=n-1;x>=0;x--){
			for(int y=0;y<m;y++){
				if(grid[x][y]){
					int left = table[x][y][0]-1;
					int right = table[x][y][1]-1;
					
//					cout << x << " " << y << " -> " << left << " " << right << "\n";
					if(must[x][y] && min(left, right) < k){
						possible = false;
						break;
					}
					
					if(min(left, right) >= k){
						for(int z=0;z<=min(left, right);z++){
							must[x-z][y-z] = false;
							must[x-z][y+z] = false;
						}
					}
				}
			}
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

