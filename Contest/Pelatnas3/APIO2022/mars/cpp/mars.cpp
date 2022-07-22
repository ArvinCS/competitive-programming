#include "mars.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n){
	assert(n <= 4);
	
	int len = (2*n+1)*(2*n+1);
	bool land[2*n+1][2*n+1];
	fill(land[0], land[2*n+1], false);
	
	for(int x=2;x>=0;x--){
		for(int y=2;y>=0;y--){
			for(int z=1;z<a[x][y].length();z++){
				if(a[x][y][z] == '1'){
					land[z/(2*n+1)][z%(2*n+1)] |= true;
				}
			}
			if(a[x][y][0] == '1'){
				land[i+x][j+y] |= true;
			}
		}
	}
	
	if((n <= 4 && k == n-1) || (n <= 6 && k == n-2)){
		bool visited[2*n+1][2*n+1];
		fill(visited[0], visited[2*n+1], false);
		
		int cnt = 0;
		for(int x=0;x<2*n+1;x++){
			for(int y=0;y<2*n+1;y++){
				if(land[x][y] && !visited[x][y]){
					cnt++;
					queue<pair<int, int>> q;
					q.push({x, y});
					
					while(!q.empty()){
						pair<int, int> p = q.front();
						q.pop();
						
						if(p.first+1 < 2*n+1 && land[p.first+1][p.second] && !visited[p.first+1][p.second]){
							visited[p.first+1][p.second] = true;
							q.push({p.first+1, p.second});
						}
						if(p.second+1 < 2*n+1 && land[p.first][p.second+1] && !visited[p.first][p.second+1]){
							visited[p.first][p.second+1] = true;
							q.push({p.first, p.second+1});
						}
						
						if(p.first > 0 && land[p.first-1][p.second] && !visited[p.first-1][p.second]){
							visited[p.first-1][p.second] = true;
							q.push({p.first-1, p.second});
						}
						if(p.second > 0 && land[p.first][p.second-1] && !visited[p.first][p.second-1]){
							visited[p.first][p.second-1] = true;
							q.push({p.first, p.second-1});
						}
					}
				}
			}
		}
		
		string ans(100, '0');
		for(int i=0;i<29;i++){
			if(cnt&(1 << i)){
				ans[i] = '1';
			}
		}
		return ans;
	} else {
		string ans(100, '0');
		if(land[i][j]){
			ans[0] = '1';
		}
		for(int x=0;x<2*n+1;x++){
			for(int y=0;y<2*n+1;y++){
				if(land[x][y]){
					if(x == i && y == j){
						ans[0] = '1';
					} else {
						ans[x*(2*n+1)+y] = '1';
					}
				}
			}
		}
		
		return ans;
	}
}
