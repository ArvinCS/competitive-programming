#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

#define ll long long

const int moveX[4] = {1, -1, 0, 0};
const int moveY[4] = {0, 0, 1, -1};
int mn = 1e9, cost = 1e9;
int n, m;
int a[250][250], c[250][250];
int visited[250][250];

void dfs(int curX, int curY, int state, int cnt, int target){
	if(cnt > mn) return;
	if(state == target){
		vector<int> v;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(visited[x][y] > 0){
					v.push_back(a[x][y]);
				}
			}
		}
		sort(v.begin(), v.end());
		
		if(mn == cnt) cost = min(cost, v[(v.size()+1)/2-1]);
		else cost = v[(v.size()+1)/2-1];
		mn = cnt;
		return;
	}
	
	for(int i=0;i<4;i++){
		int newX = curX+moveX[i], newY = curY+moveY[i];
		
		if(newX >= 0 && newX < n && newY >= 0 && newY < m && visited[newX][newY] < 2 && c[newX][newY] > 0 && (target&(1 << c[newX][newY]))){
			visited[newX][newY]++;
			dfs(newX, newY, state|(1 << c[newX][newY]), cnt+(visited[newX][newY] == 1 ? 1 : 0), target);
			visited[newX][newY]--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> c[x][y];
		}
	}
	
	fill(visited[0], visited[n], 0);
	
	for(int state=0;state<(1 << 9);state++){
		if(__builtin_popcount(state) != 5) continue;
		if(state&1) continue;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(state&(1 << c[x][y])){
					visited[x][y]++;
					dfs(x, y, (1 << c[x][y]), 1, state);
					visited[x][y]--;
				}
			}
		}
	}
	
	cout << mn << " " << cost << "\n";
	return 0;
}
