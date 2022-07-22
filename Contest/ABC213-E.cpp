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

int placeX[4] = {-1, -1, 0, 0};
int placeY[4] = {-1, 0, -1, 0};

int punchX[4] = {0, 0, 1, 1};
int punchY[4] = {0, 1, 0, 1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w;
	cin >> h >> w;
	
	bool grid[h][w];
	for(int x=0;x<h;x++){
		for(int y=0;y<w;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == '.');
		}
	}

	int dist[h][w];
	fill(dist[0], dist[h], inf_int);
	
	priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<tuple<int, int, int, bool>>> pq;
	dist[0][0] = 0;
	pq.push(make_tuple(dist[0][0], 0, 0, false));
	
	while(!pq.empty()){
		tuple<int, int, int, bool> t = pq.top();
		pq.pop();
		
		int cost = get<0>(t), curX = get<1>(t), curY = get<2>(t);
		bool passed = get<3>(t);
		
		if(grid[curX][curY]){
			for(int i=0;i<4;i++){
				int newX = curX+moveX[i];
				int newY = curY+moveY[i];
				
				if(newX >= 0 && newX < h && newY >= 0 && newY < w){
					if(dist[newX][newY] > cost+(!grid[newX][newY])){
						dist[newX][newY] = cost+(!grid[newX][newY]);
						pq.push(make_tuple(dist[newX][newY], newX, newY, false));
					}
				}
			}
		} else {
			if(passed){
				for(int i=0;i<4;i++){
					int newX = curX+moveX[i];
					int newY = curY+moveY[i];
					
					if(newX >= 0 && newX < h && newY >= 0 && newY < w){
						if(dist[newX][newY] > cost+(!grid[newX][newY])){
							dist[newX][newY] = cost+(!grid[newX][newY]);
							pq.push(make_tuple(dist[newX][newY], newX, newY, false));
						}
					}
				}
			} else {
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						int newX = curX+placeX[i]+punchX[j];
						int newY = curY+placeY[i]+punchY[j];
						
						if(newX >= 0 && newX < h && newY >= 0 && newY < w){
							if(dist[newX][newY] > cost){
								dist[newX][newY] = cost;
								pq.push(make_tuple(dist[newX][newY], newX, newY, true));
							}
						}
					}
				}
			}
		}
	}
	
	cout << dist[h-1][w-1] << "\n";
    return 0;
}

