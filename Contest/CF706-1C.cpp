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

const int maxN = 250005;

int parrent[maxN], sz[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		char grid[n][m];
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
			}
		}
		
		char ans[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				ans[x][y] = grid[x][y];
			}
		}
		
		for(int y=1;y<m;y+=3){
			bool connect = false;
			for(int x=0;x<n;x++){
				ans[x][y] = 'X';
				
				if(!connect && y+2 < m){
					if(grid[x][y+1] == 'X'){
						ans[x][y+2] = 'X';
						connect = true;
					} else if(grid[x][y+2] == 'X'){
						ans[x][y+1] = 'X';
						connect = true;
					}
				}
			}
			
			if(!connect && y+2 < m){
				ans[0][y+1] = ans[0][y+2] = 'X';
			}
		}
		
		if(m == 1){
			for(int x=0;x<n;x++){
				ans[x][0] = 'X';	
			}
		}
		if(m >= 3 && m % 3 == 1){
			for(int x=2;x<n;x++){
				if(grid[x][m-1] == 'X'){
					ans[x][m-2] = 'X'; 
				}
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cout << ans[x][y];
			}
			cout << "\n";
		}
	}

    return 0;
}

