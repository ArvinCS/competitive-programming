#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	char grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	queue<pair<int, int>> q;
	int dist[n][m];
	
	fill(dist[0], dist[n], -1);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] == 'X'){
				bool edge = false;
				for(int newX=x-1;newX<=x+1;newX++){
					for(int newY=y-1;newY<=y+1;newY++){
						if(newX == x && newY == y) continue;
						if(newX < 0 || newX >= n || newY < 0 || newY >= m){
							edge = true;
							continue;
						}
						
						if(grid[newX][newY] == '.'){
							edge = true;
						}
					}
				}
				
				if(edge){
					q.push({x, y});
					dist[x][y] = 0;
				}
			}
		}
	}
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		for(int newX=p.first-1;newX<=p.first+1;newX++){
			for(int newY=p.second-1;newY<=p.second+1;newY++){
				if(newX == p.first && newY == p.second) continue;
				if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
				
				if(grid[newX][newY] == 'X' && dist[newX][newY] == -1){
					dist[newX][newY] = dist[p.first][p.second]+1;
					q.push({newX, newY});
				}
			}
		}
	}
	
	int ans = 0;
	int left = 1, right = min(n, m)-1;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		queue<pair<int, int>> q;
		int dist2[n][m];
		fill(dist2[0], dist2[n], -1);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(grid[x][y] == 'X' && dist[x][y] >= mid){
					dist2[x][y] = mid;
					q.push({x, y});
				}
			}
		}
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			for(int newX=p.first-1;newX<=p.first+1;newX++){
				for(int newY=p.second-1;newY<=p.second+1;newY++){
					if(newX == p.first && newY == p.second) continue;
					if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
					
					if(grid[newX][newY] == 'X' && dist2[newX][newY] == -1){
						dist2[newX][newY] = dist2[p.first][p.second]-1;
						q.push({newX, newY});
					}
				}
			}
		}
		
		bool possible = true;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(grid[x][y] == 'X' && dist2[x][y] < 0){
					possible = false;
					break;
				}
			}
		}
		
		if(possible){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(dist[x][y] >= ans){
				cout << "X";
			} else {
				cout << ".";
			}
		}
		cout << "\n";
	}
    return 0;
}

