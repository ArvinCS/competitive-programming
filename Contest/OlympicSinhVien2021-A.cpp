#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int n, k;

vector<pair<int, int>> ask(int x, int y){
	cout << "ASK " << x+1 << " " << y+1 << endl;
	
	vector<pair<int, int>> v;
	for(int x=0;x<k-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		v.push_back({a, b});
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	cin >> n >> k;
	
	bool visited[n*k][n*k];
	fill(visited[0], visited[n*k], false);
	
	vector<vector<pair<int, int>>> ans;
	for(int i=0;i<4;i++){
		bool ok = true;
		while(ok){
			ok = false;
			
			bool found = true;
			while(found){
				found = false;
				for(int x=0;x<n*k;x++){
					for(int y=0;y<n*k;y++){
						if(visited[x][y]) continue;
						
						int dir = 0;
						int cnt = 0, mx = 0;
						for(int i=0;i<4;i++){
							int newX = x+moveX[i], newY = y+moveY[i];
							if(newX >= 0 && newX < n*k && newY >= 0 && newY < n*k){
								cnt += visited[newX][newY];
								mx++;
								if(!visited[newX][newY]) dir = i;
							}
						}
						
						if(cnt == mx-1){
							vector<pair<int, int>> w;
							int curX = x, curY = y;
							for(int i=0;i<k;i++){
								w.push_back({curX, curY});
								visited[curX][curY] = true;
								
								int newX = curX+moveX[dir], newY = curY+moveY[dir];
								if(newX >= 0 && newX < n*k && newY >= 0 && newY < n*k){
									curX = newX;
									curY = newY;
								}
							}
							
							found = true;
							ans.push_back(w);
						}
					}
				}
			}
			
			vector<pair<int, int>> v;
			for(int x=0;x<n*k;x++){
				for(int y=0;y<n*k;y++){
					if(visited[x][y]) continue;
					
					int cnt = 0, mx = 0;
					for(int i=0;i<4;i++){
						int newX = x+moveX[i], newY = y+moveY[i];
						if(newX >= 0 && newX < n*k && newY >= 0 && newY < n*k){
							cnt += visited[newX][newY];
							mx++;
						}
					}
					
					if(cnt == i && cnt < mx-1){
						v.push_back({x, y});
					}
				}
			}
			
			if(!v.empty()){
				int md = max(1, (int) sqrt(v.size()));
				int tmp = (rng()-1) % md + 1;
				for(int x=0;x<tmp;x++){
					if(v.empty()) break;
					
					int idx = rng() % v.size();
					while(visited[v[idx].first][v[idx].second] && !v.empty()){
						swap(v[idx], v[v.size()-1]);
						v.pop_back();
						
						if(v.empty()) break;
						
						idx = rng() % v.size();
					}
					if(v.empty()) break;
					
					vector<pair<int, int>> w = ask(v[idx].first, v[idx].second);
					w.push_back(v[idx]);
					for(auto p : w){
						visited[p.first][p.second] = true;
					}
					ans.push_back(w);
					ok = true;
				}
			}
		}
	}
	
	cout << "ANSWER" << endl;
	for(auto w : ans){
		for(int x=0;x<w.size();x++){
			if(x > 0) cout << " ";
			cout << w[x].first+1 << " " << w[x].second+1;
		}
		cout << endl;
	}
	return 0;
}
