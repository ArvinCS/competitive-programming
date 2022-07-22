#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {1, 1, -1, -1};
int moveY[4] = {1, -1, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int ax, ay;
	cin >> ax >> ay;
	
	int bx, by;
	cin >> bx >> by;
	
	char grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y];
		}
	}
	
	int dist[n][n];
	fill(dist[0], dist[n], -1);
	
	ax--; ay--; bx--; by--;
	
	queue<pair<int, int>> q;
	dist[ax][ay] = 0;
	q.push({ax, ay});
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		for(int j=0;j<4;j++){
			int cnt = 0;
			for(int i=1;i<n;i++){
				int curX = p.first+i*moveX[j];
				int curY = p.second+i*moveY[j];
				
				if(curX >= 0 && curX < n && curY >= 0 && curY < n){
					if(grid[curX][curY] == '#') break;
					
					if(dist[curX][curY] == -1){
						dist[curX][curY] = dist[p.first][p.second]+1;
						q.push({curX, curY});
					} else if(dist[curX][curY] < dist[p.first][p.second]+1){
						break;
					}
				} else {
					break;
				}
			}
		}
	}
	
	cout << dist[bx][by] << "\n";
    return 0;
}

