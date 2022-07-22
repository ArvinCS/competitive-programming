#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int r, c;
	cin >> r >> c;
	
	char grid[r][c];
	for(int x=0;x<r;x++){
		for(int y=0;y<c;y++){
			cin >> grid[x][y];
		}
	}
	
	bool visited[r][c];
	fill(visited[0], visited[r], false);
	
	vector<vector<char>> v;
	for(int x=0;x<r;x++){
		for(int y=0;y<c;y++){
			if(!visited[x][y]){
				int hor = c-1-y;
				int ver = r-1-x;
				
				vector<char> w;
				w.push_back(grid[x][y]);
				if(hor != y) w.push_back(grid[x][hor]);
				if(ver != x) w.push_back(grid[ver][y]);
				if(hor != y && ver != x) w.push_back(grid[ver][hor]);
				v.push_back(w);
				
				visited[x][y] = visited[x][hor] = visited[ver][y] = visited[ver][hor] = true;
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<v.size();x++){
		int mn = 1e9;
		for(int y=0;y<26;y++){
			int cnt = 0;
			for(auto c : v[x]){
				int val = (c - 'A');
				cnt += min((val - y + 26) % 26, (y - val + 26) % 26);
			}
			mn = min(mn, cnt);
		}
		ans += mn;
	}
	
	cout << ans << "\n";
	return 0;
}
