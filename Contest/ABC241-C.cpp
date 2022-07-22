#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	char grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y];
		}
	}
	
	bool possible = false;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x+5 < n && y-5 >= 0){
				int cnt = 0;
				for(int i=0;i<=5;i++){
					if(grid[x+i][y-i] == '.'){
						cnt++;
					}
				}
				
				if(cnt <= 2){
					possible = true;
				}
			}
			if(x+5 < n && y+5 < n){
				int cnt = 0;
				for(int i=0;i<=5;i++){
					if(grid[x+i][y+i] == '.'){
						cnt++;
					}
				}
				
				if(cnt <= 2){
					possible = true;
				}
			}
			if(x+5 < n){
				int cnt = 0;
				for(int i=0;i<=5;i++){
					if(grid[x+i][y] == '.'){
						cnt++;
					}
				}
				
				if(cnt <= 2){
					possible = true;
				}
			}
			if(y+5 < n){
				int cnt = 0;
				for(int i=0;i<=5;i++){
					if(grid[x][y+i] == '.'){
						cnt++;
					}
				}
				
				if(cnt <= 2){
					possible = true;
				}
			}
		}
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}

