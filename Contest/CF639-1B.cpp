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

const int maxN = 1e3 + 5;

bool grid[maxN][maxN];
int moveX[4] = {1, -1, 0 ,0};
int moveY[4] = {0, 0, 1, -1};
int n, m;

void dfs(int curX, int curY){
	grid[curX][curY] = false;
	for(int i=0;i<4;i++){
		int newX = curX+moveX[i];
		int newY = curY+moveY[i];
		
		if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY]){
			dfs(newX, newY);
		}
	}
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
			char c;
			cin >> c;
			
			grid[x][y] = (c == '#');
		}
	}
	
	bool row[n], col[m];
	for(int x=0;x<n;x++){
		bool exist = false;
		for(int y=0;y<m;y++){
			if(grid[x][y]) exist = true;
		}
		row[x] = exist;
	}
	for(int y=0;y<m;y++){
		bool exist = false;
		for(int x=0;x<n;x++){
			if(grid[x][y]) exist = true;
		}
		col[y] = exist;
	}
	
	for(int x=0;x<n;x++){
		if(!row[x]){
			bool found = false;
			for(int y=0;y<m;y++){
				if(!col[y]) found = true;
			}
			
			if(!found){
				cout << "-1\n";
				return 0;
			}
		}
	}
	for(int y=0;y<m;y++){
		if(!col[y]){
			bool found = false;
			for(int x=0;x<n;x++){
				if(!row[x]) found = true;
			}
			
			if(!found){
				cout << "-1\n";
				return 0;
			}
		}
	}
	for(int x=0;x<n;x++){
		int y;
		for(y=0;y<m;y++){
			if(y+1 < m && grid[x][y] && !grid[x][y+1]) break;
		}
		y++;
		for(;y<m;y++){
			if(grid[x][y]) break;
		}
		
		if(y < m){
			cout << "-1\n";
			return 0;
		}
	}
	for(int y=0;y<m;y++){
		int x;
		for(x=0;x<n;x++){
			if(x+1 < n && grid[x][y] && !grid[x+1][y]) break;
		}
		x++;
		for(;x<n;x++){
			if(grid[x][y]) break;
		}
		
		if(x < n){
			cout << "-1\n";
			return 0;
		}
	}
	
	int ans = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y]){
				ans++;
				dfs(x, y);
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

