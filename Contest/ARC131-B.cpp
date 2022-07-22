#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == '.' ? -1 : (c - '0'));
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] != -1) continue;
			
			bool done[6];
			fill(done, done+6, false);
			
			for(int i=0;i<4;i++){
				int newX = x+moveX[i], newY = y+moveY[i];
				
				if(newX >= 0 && newX < n && newY >= 0 && newY < m){
					if(grid[newX][newY] >= 0){
						done[grid[newX][newY]] = true;
					}
				}
			}
			
			for(int z=1;z<6;z++){
				if(!done[z]){
					grid[x][y] = z;
					break;
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cout << grid[x][y];
		}
		cout << "\n";
	}
    return 0;
}

