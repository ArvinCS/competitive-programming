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

int n, m;
int grid[305][305];

int a[4] = {0, 0, 1, -1};
int b[4] = {1, -1, 0, 0};

void dfs(int curX, int curY, int min, bool visited[305][305]){	
	for(int x=0;x<4;x++){
		if(curX+a[x] >= 0 && curX+a[x] < n){
			if(curY+b[x] >= 0 && curY+b[x] < m){
				if(!visited[curX+a[x]][curY+b[x]] && grid[curX+a[x]][curY+b[x]] > min){
					visited[curX+a[x]][curY+b[x]] = true;
					dfs(curX+a[x], curY+b[x], min, visited);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	unordered_set<int> s;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			s.insert(grid[x][y]);
		}
	}
	
	int ans = 1;
	for(unordered_set<int>::iterator it=s.begin();it!=s.end();it++){
		int num = *it;
		bool visited[305][305];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++) visited[x][y] = false;
		}
		
		int cnt = 0;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(!visited[x][y] && grid[x][y] > num){
					visited[x][y] = true;
					dfs(x, y, num, visited);
					cnt++;
				}
			}
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

