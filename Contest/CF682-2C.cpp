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
		int n, m;
		cin >> n >> m;
		
		int grid[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if((x+y)%2 == 0){
					if(grid[x][y]&1) grid[x][y]++;
				} else {
					if(grid[x][y]%2 == 0) grid[x][y]++;
				}
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(y>0) cout << " ";
				cout << grid[x][y];
			}
			cout << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

