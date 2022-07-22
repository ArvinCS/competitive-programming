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

int dist[255][255];
char grid[255][255];

char dx[4] = {0,0,1,-1};
char dy[4] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, m;
		cin >> n >> m;
		
		queue<pair<int, int>> v;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
				dist[x][y] = -1;

				if(grid[x][y] == '1'){
					v.push({x, y});
					dist[x][y] = 0;
				}
			}
		}
		
		int most = 0;
		while(!v.empty()){
			pair<int, int> p = v.front();
			v.pop();
			
			for(int x=0;x<4;x++){
				int curX = p.first + dx[x], curY = p.second + dy[x];
				if(curX >= 0 && curX < n && curY >= 0 && curY < m && dist[curX][curY] == -1){
					dist[curX][curY] = 1 + dist[p.first][p.second];
					most = max(most, dist[curX][curY]);
					v.push({curX, curY});
				}
			}
		}
		
		int left = 1, right = most, ans;
		while(left < right){
			int mid = (left+right) >> 1;
			int cnt = 0;
			
			int a = -m-n, b = -m-n, c = m+n, d = m+n;
			
			for(int x=0;x<n;x++){
				for(int y=0;y<m;y++){
					if(dist[x][y] > mid){
						cnt++;
						
						a = min(a, -x-y);
						b = max(b, -x-y);
						c = min(c, x+y);
						d = max(d, x+y);
					}
				}
			}
			
			bool valid = (cnt == 0);
			if(!valid){
				for(int x=0;x<n;x++){
					for(int y=0;y<m;y++){
						if(max(abs(a-m+n), abs(b-m+n), abs(c-m-n), abs(d-m-n)) <= mid){
							valid = true;
						} else {
							valid = false;
							break;
						}
					}
				}
			}
			
			if(valid){
				right = mid;
			} else {
				left = mid+1;
			}
		}
		
		cout << "Case #" << i << ": " << right << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

