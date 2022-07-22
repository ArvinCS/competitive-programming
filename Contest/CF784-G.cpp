#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
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
		for(int y=0;y<m;y++){
			int cnt = 0;
			for(int x=0;x<n;x++){
				ans[x][y] = '.';
				
				if(grid[x][y] == '*'){
					cnt++;
				} else if(grid[x][y] == 'o'){
					for(int z=x-1;z>=x-cnt;z--){
						ans[z][y] = '*';
					}
					cnt = 0;
					ans[x][y] = 'o';
				}
			}
			
			for(int z=n-1;z>=n-cnt;z--){
				ans[z][y] = '*';
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

