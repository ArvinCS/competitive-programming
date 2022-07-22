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

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		queue<pair<int, int>> q;
		char grid[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
				if(grid[x][y] == 'L') q.push({x, y});
			}
		}
		
		int cnt[n][m], cur[n][m];
		fill(cnt[0], cnt[n], 0);
		fill(cur[0], cur[n], 0);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				for(int i=0;i<4;i++){
					int newX = x+moveX[i], newY = y+moveY[i];
					if(newX >= 0 && newX < n && newY >= 0 && newY < m){
						if(grid[newX][newY] != '#'){
							cnt[x][y]++;
						}
					}
				}
			}
		}
		
		
		bool visited[n][m][4];
		fill(*visited[0], *visited[n], false);
		
		for(int i=0;i<4;i++){
			visited[q.front().first][q.front().second][i] = true;
		}
		
		while(!q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			
			for(int i=0;i<4;i++){
				int newX = x+moveX[i], newY = y+moveY[i];
				if(newX >= 0 && newX < n && newY >= 0 && newY < m){
					if(grid[newX][newY] != '#' && !visited[newX][newY][i]){
						visited[newX][newY][i] = true;
						cur[newX][newY]++;
						
						if(cnt[newX][newY]-cur[newX][newY] == 1 || cnt[newX][newY] == 1){
							grid[newX][newY] = '+';
							q.push({newX, newY});
						}
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
	}

    return 0;
}

