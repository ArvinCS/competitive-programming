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
		int n;
		cin >> n;
		
		char grid[n][n];
		int cnt[2][3];
		fill(cnt[0], cnt[2], 0);
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> grid[x][y];
				if(grid[x][y] != '.'){
					if(grid[x][y] == 'X'){
						cnt[0][(x+y)%3]++;
					} else {
						cnt[1][(x+y)%3]++;
					}
				}
			}
		}
		
		if(cnt[0][0] <= cnt[0][1] && cnt[0][0] <= cnt[0][2]){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if((x+y)%3 == 0){
						grid[x][y] = '.';
					}
				}
			}
		} else if(cnt[0][1] <= cnt[0][0] && cnt[0][1] <= cnt[0][2]){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if((x+y)%3 == 1){
						grid[x][y] = '.';
					}
				}
			}
		} else {
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if((x+y)%3 == 2){
						grid[x][y] = '.';
					}
				}
			}
		}
		
		if(cnt[1][0] <= cnt[1][1] && cnt[1][0] <= cnt[1][2]){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if((x+y)%3 == 0){
						grid[x][y] = '.';
					}
				}
			}
		} else if(cnt[1][1] <= cnt[1][0] && cnt[1][1] <= cnt[1][2]){
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if((x+y)%3 == 1){
						grid[x][y] = '.';
					}
				}
			}
		} else {
			for(int x=0;x<n;x++){
				for(int y=0;y<n;y++){
					if((x+y)%3 == 2){
						grid[x][y] = '.';
					}
				}
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout << grid[x][y];
			}
			cout << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

