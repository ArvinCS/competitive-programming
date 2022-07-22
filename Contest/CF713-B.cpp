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
		
		int row1 = -1, row2 = -1, col1 = -1, col2 = -1;
		char grid[n][n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> grid[x][y];
				if(grid[x][y] == '*'){
					if(row1 == -1){
						row1 = x;
						col1 = y;
					} else {
						row2 = x;
						col2 = y;
					}
				}
			}
		}
		
		if(row1 != row2 && col1 != col2){
			grid[row1][col2] = '*';
			grid[row2][col1] = '*';
		} else {
			if(row1 == row2){
				if(row1 > 0){
					grid[row1-1][col1] = '*';
					grid[row1-1][col2] = '*';
				} else {
					grid[row1+1][col1] = '*';
					grid[row1+1][col2] = '*';
				}
			} else {
				if(col1 > 0){
					grid[row1][col1-1] = '*';
					grid[row2][col1-1] = '*';
				} else {
					grid[row1][col1+1] = '*';
					grid[row2][col1+1] = '*';
				}
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++) cout << grid[x][y];
			cout << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

