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

const int maxN = 2000;

int n;
short grid[maxN][maxN];

void dfs(int curX, int curY){
	if(curX < 0 || curX > n || curY < 0 || curY > n || grid[curX][curY] == 0) return;
	
	grid[curX][curY] = 0;
	dfs(curX+1, curY);
	dfs(curX-1, curY);
	dfs(curX, curY+1);
	dfs(curX, curY-1);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			char tmp;
			cin >> tmp;
			
			grid[x][y] = (tmp - '0');
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(x == 0 || y == 0 || x == n-1 || y == n-1){
				dfs(x, y);
			}
		}
	}
	
	short ans = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(grid[x][y] == 1){
				dfs(x,y);
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

