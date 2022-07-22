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

const int maxN = 30;

int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};
int grid[maxN][maxN], n, m;

void down(){ // O(nm)
	for(int y=0;y<m;y++){
		int lastX = n-1;
		for(int x=n-1;x>=0;x--){
			if(grid[x][y] == -1) continue;
			
			while(lastX >= 0 && grid[lastX][y] >= 0){
				lastX--;
			}
			
			if(lastX <= x){
				continue;
			}
			
			swap(grid[x][y], grid[lastX][y]);
		}
	}
}

ll solve(ll cnt){
	bool visited[n][m];
	fill(visited[0], visited[n], false);
	
	vector<vector<pair<int, int>>> group;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(!visited[x][y] && grid[x][y] >= 0){
				vector<pair<int, int>> v;
				queue<pair<int, int>> q;
				q.push({x, y});
				visited[x][y] = true;
				
				while(!q.empty()){
					int x = q.front().first, y = q.front().second;
					q.pop();
					
					v.push_back({x, y});
					
					for(int i=0;i<4;i++){
						if(x+dirX[i] < 0 || x+dirX[i] >= n || y+dirY[i] < 0 || y+dirY[i] >= m) continue;
						if(!visited[x+dirX[i]][y+dirY[i]] && grid[x+dirX[i]][y+dirY[i]] == grid[x][y]){
							visited[x+dirX[i]][y+dirY[i]] = true;
							q.push({x+dirX[i], y+dirY[i]});
						}
					}
				}
				if(v.size() > 1) group.push_back(v);
			}
		}
	}
	
	if(group.size() == 0){
		return cnt;
	}
	
	int old[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++) old[x][y] = grid[x][y];
	}
	
	ll ans = 0;
	for(auto v : group){
		for(auto pos : v){
			grid[pos.first][pos.second] = -1;
		}
		
		down();
		ans = max(ans, solve(cnt+v.size()*(v.size()-1)));
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++) grid[x][y] = old[x][y];
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}		
	
	cout << solve(0) << "\n";
	
    return 0;
}

