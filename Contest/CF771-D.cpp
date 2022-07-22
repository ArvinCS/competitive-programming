#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1005;

int c[maxN][maxN];
int a[maxN][maxN];
int n, m;
int moveX[4] = {0, 0, 1, 1};
int moveY[4] = {0, 1, 0, 1};

bool customSort(pair<int, int> a, pair<int, int> b){
	if(min(a.first, n-1-a.first) == min(b.first, n-1-b.first)){
		return a.second < b.second;
	}
	return min(a.first, n-1-a.first) < min(b.first, n-1-b.first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> c[x][y];
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			a[x][y] = c[x][y];
		}
	}
	
	vector<tuple<int, int, int>> ans;
	queue<pair<int, int>> q;
	
	for(int x=0;x+1<n;x++){
		for(int y=0;y+1<n;y++){
			bool same = true;
			for(int i=0;i<4;i++){
				int newX = x+moveX[i], newY = y+moveY[i];
				
				if(c[newX][newY] != c[x][y]){
					same = false;
					break;
				}
			}
			
			if(same){
				q.push({x, y});
				continue;
			}
		}
	}
	
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		
		if(a[p.first][p.second] == 0) continue;
		
		bool valid = false;
		for(int x=-1;x<=0;x++){			
			for(int y=-1;y<=0;y++){
				int newX = p.first+x, newY = p.second+y;
				if(newX >= 0 && newX < n-1 && newY >= 0 && newY < m-1){
					bool same = true;
					for(int i=0;i<4;i++){
						int newX2 = newX+moveX[i], newY2 = newY+moveY[i];
						
						if(a[newX2][newY2] > 0 && a[newX2][newY2] != c[p.first][p.second]){
							same = false;
							break;
						}
					}
										
					if(same){
						ans.push_back(make_tuple(newX, newY, c[p.first][p.second]));
						valid = true;
						for(int i=0;i<4;i++){
							int newX2 = newX+moveX[i], newY2 = newY+moveY[i];
							
							a[newX2][newY2] = 0;
						}
						break;
					}
				}
			}
		}
		
		if(!valid) continue;
		for(int newX=-2;newX<=2;newX++){
			for(int newY=-2;newY<=2;newY++){
				if(p.first+newX >= 0 && p.first+newX < n && p.second+newY >= 0 && p.second+newY < m){
					if(a[p.first+newX][p.second+newY] > 0){
						q.push({p.first+newX, p.second+newY});
					}
				}
			}
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	bool possible = true;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(a[x][y] != 0){
				possible = false;
				break;
			}
		}
	}
	
	if(!possible){
		cout << "-1\n";
		return 0;
	}
	
	cout << ans.size() << "\n";
	for(auto t : ans){
		cout << get<0>(t)+1 << " " << get<1>(t)+1 << " " << get<2>(t) << "\n";
	}
    return 0;
}

