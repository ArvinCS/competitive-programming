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

	int n, m, t;
	cin >> n >> m >> t;
	
	int grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c - '0');
		}
	}
	
	bool visited[n][m];
	ll table[n][m];
	fill(visited[0], visited[n], false);
	fill(table[0], table[n], inf_ll);
	
	queue<pair<int, int>> q;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			bool same = false;
			for(int z=0;z<4;z++){
				if(x+moveX[z] >= 0 && x+moveX[z] < n && y+moveY[z] >= 0 && y+moveY[z] < m){
					if(grid[x+moveX[z]][y+moveY[z]] == grid[x][y]){
						same = true;
						break;
					}
				}
			}
			
			if(same){
				table[x][y] = 0;
				q.push({x, y});
			}
		}
	}
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		if(visited[p.first][p.second]) continue;
		visited[p.first][p.second] = true;
		
		for(int z=0;z<4;z++){
			int newX = p.first+moveX[z], newY = p.second+moveY[z];
			if(newX >= 0 && newX < n && newY >= 0 && newY < m){
				if(table[newX][newY] > table[p.first][p.second]+1){
					table[newX][newY] = table[p.first][p.second]+1;
					q.push({newX, newY});
				}
			}
		}
	}
	
	while(t--){
		int x, y;
		ll p;
		cin >> x >> y >> p;
		
		x--; y--;
		p--;
		if(table[x][y] <= p){
			bool change = ((p-table[x][y]) % 2 == 0);
			cout << (grid[x][y]^change) << "\n";
		} else {
			cout << grid[x][y] << "\n";
		}
	}
    return 0;
}

