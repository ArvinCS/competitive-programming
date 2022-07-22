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

const int maxN = 15;

char grid[maxN][maxN];
bool valid[maxN][maxN];

int find(int curX, int curY){
	return (grid[curX-1][curY] == '#') + (grid[curX+1][curY] == '#') + (grid[curX][curY-1] == '#') + (grid[curX][curY+1] == '#');  
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int r = 1, c = 1;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
			if(grid[x][y] == '#'){
				r = max(r, x);
				c = max(c, y);
			}
		}
	}
	
	int ans = 4;
	for(int x=1;x<n-1;x++){
		for(int y=1;y<m-1;y++){
			if(grid[x][y] == '.' && find(x,y) >= 2){
				if(x == 1 || y == 1 || x == r || y == c) ans--;
				if(grid[x-1][y] == '#') ans++;
				if(grid[x+1][y] == '#') ans++;
				if(grid[x][y-1] == '#') ans++;
				if(grid[x][y+1] == '#') ans++;
			}
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

