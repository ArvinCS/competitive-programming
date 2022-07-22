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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		bool grid[2][n];
		for(int i=0;i<2;i++){
			for(int x=0;x<n;x++){
				char tmp;
				cin >> tmp;
				
				grid[i][x] = (tmp - '0');
			}
		}
		
		int ans = 0;
		for(int x=0;x<n;x++){
			if(!grid[0][x] && grid[1][x]){
				grid[1][x] = false;
				ans++;
			}
		}
		
		for(int x=0;x<n;x++){
			if(grid[1][x]){
				if(x-1 >= 0 && grid[0][x-1]){
					grid[0][x-1] = grid[1][x] = false;
					ans++;
				} else if(x+1 < n && grid[0][x+1]){
					grid[0][x+1] = grid[1][x] = false;
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

