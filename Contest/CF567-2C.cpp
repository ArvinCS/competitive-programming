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

	int n, m;
	cin >> n >> m;
	
	char grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	int suffixCol[n][m];
	int suffixRow[n][m];	
	for(int x=0;x<n;x++){
		suffixRow[x][m-1] = 1;
	}
	for(int x=0;x<m;x++){
		suffixCol[n-1][x] = 1;
	}
	
	for(int x=0;x<n;x++){
		for(int y=m-2;y>=0;y--){
			suffixRow[x][y] = 1;
			if(grid[x][y] == grid[x][y+1]){
				suffixRow[x][y] += suffixRow[x][y+1];
			}
		}
	}
	
	for(int y=0;y<m;y++){
		for(int x=n-2;x>=0;x--){
			suffixCol[x][y] = 1;
			if(grid[x][y] == grid[x+1][y]){
				suffixCol[x][y] += suffixCol[x+1][y];
			}		
		}
	}
	
	int ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+2;y<n;y+=3){
			for(int z=0;z<m;z++){
				int parity = (y-x+1)/3;
				
				if(suffixCol[x][z] == parity && suffixCol[x+parity][z] == parity && suffixCol[x+2*parity][z] >= parity){
					int mn = inf_int;
					for(int i=x;i<=y;i++){
						mn = min(mn, suffixRow[i][z]);
					}
					
					ans += mn;
				}
			}
		}
	}
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

