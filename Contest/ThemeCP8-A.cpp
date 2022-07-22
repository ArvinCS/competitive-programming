#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

bool grid[50][50];
bool reach[2][50][50];
int n;

void bfs(int id, int r, int c){
	queue<pair<int, int>> q;
	q.push({r, c});
	reach[id][r][c] = true;
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int newX = p.first+moveX[i], newY = p.second+moveY[i];
			if(newX >= 0 && newX < n && newY >= 0 && newY < n){
				if(grid[newX][newY] && !reach[id][newX][newY]){
					reach[id][newX][newY] = true;
					q.push({newX, newY});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	int r1, c1;
	cin >> r1 >> c1;
	
	int r2, c2;
	cin >> r2 >> c2;
	
	r1--; c1--;
	r2--; c2--;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == '0');
		}
	}
	
	fill(*reach[0], *reach[2], false);
	
	bfs(0, r1, c1);
	bfs(1, r2, c2);
	
	int ans = 1e9;
	if(reach[0][r2][c2]){
		ans = 0;
	}
	
	for(int x1=0;x1<n;x1++){
		for(int y1=0;y1<n;y1++){
			for(int x2=0;x2<n;x2++){
				for(int y2=0;y2<n;y2++){
					if(reach[0][x1][y1] && reach[1][x2][y2]){
						ans = min(ans, (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
					}
				}
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

