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

const int maxM = 2e3 + 5;

int prefix[maxM], suffix[maxM];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		int grid[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
			}
		}	
		
		for(int y=0;y<m;y++){
			prefix[y] = max(grid[0][y], (y-1 >= 0 ? prefix[y-1] : 0));
		}
		for(int y=m-1;y>=0;y--){
			suffix[y] = max(grid[0][y], (y+1 < m ? suffix[y+1] : 0));
		}
		
		for(int x=1;x<n;x++){
			for(int y=0;y<m;y++){
				grid[x][y] += max((y-1 >= 0 ? prefix[y-1] : 0), (y+1 < m ? suffix[y+1] : 0));
			}
			
			for(int y=0;y<m;y++){
				prefix[y] = max(grid[x][y], (y-1 >= 0 ? prefix[y-1] : 0));
			}
			for(int y=m-1;y>=0;y--){
				suffix[y] = max(grid[x][y], (y+1 < m ? suffix[y+1] : 0));
			}
		}
				
		cout << prefix[m-1] << "\n";
	}

    return 0;
}

