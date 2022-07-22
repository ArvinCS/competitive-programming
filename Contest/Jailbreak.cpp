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

int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int r, c;
		cin >> r >> c;
		
		vector<pair<int, int>> v;
		char data[r][c];
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				cin >> data[x][y];
				
				if(data[x][y] == '$'){
					v.push_back({x, y});
				}
			}
		}
		
		int dist[r][c];
		pair<int, int> prev[r][c];
		bool visited[r][c];
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				dist[x][y] = inf_int;
				prev[x][y] = {-1, -1};
				visited[x][y] = false;
			}
		}
		
		deque<pair<int ,int>> q;
		dist[v[0].first][v[0].second] = 0;
		q.push_front({v[0].first, v[0].second});
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop_front();
			
			for(int i=0;i<4;i++){
				int curX = p.first+a[i], curY = p.second+b[i];
				if(curX >= 0 && curX < r && curY >= 0 && curY < c){
					bool door = (data[curX][curY] == '#');
					if(data[curX][curY] != '*' && dist[p.first][p.second]+(door) < dist[curX][curY]){
						dist[curX][curY] = dist[p.first][p.second]+door;
						prev[curX][curY] = p;
						if(door){
							q.push_back({curX, curY});
						} else {
							q.push_front({curX, curY});
						}
					}
				}
			}		
		}
		
		pair<int, int> best;
		int cnt = inf_int;
		for(int x=0;x<r;x++){
			if(dist[x][0] < cnt){
				cnt = dist[x][0];
				best = {x, 0};
			}
			if(dist[x][c-1] < cnt){
				cnt = dist[x][c-1];
				best = {x, c-1};
			}
		}
		for(int x=0;x<c;x++){
			if(dist[0][x] < cnt){
				cnt = dist[0][x];
				best = {0, x};
			}
			if(dist[r-1][x] < cnt){
				cnt = dist[r-1][x];
				best = {r-1, x};
			}
		}
		
		while(prev[best.first][best.second].first != -1){
			visited[best.first][best.second] = true;
			best = prev[best.first][best.second];
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

