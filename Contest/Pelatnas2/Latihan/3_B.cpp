#include <bits/stdc++.h>

using namespace std;

#define ll long long

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

const int maxN = 305;

int n, m;
bool visited[maxN][maxN];
ll a[maxN][maxN];
vector<pair<int, int>> ans;

void dfs(int curX, int curY, ll cur, vector<pair<int, int>> v){
	if(cur < 0) return;
	if(v.size() == n*m){
		if(abs(v[0].first-v.back().first)+abs(v[0].second-v.back().second) <= 1) ans = v;
		return;
	}
	if(ans.size() == n*m) return;
	
	for(int i=0;i<4;i++){
		int newX = curX+moveX[i], newY = curY+moveY[i];
		if(newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY]){
			v.push_back({newX, newY});
			visited[newX][newY] = true;
			dfs(newX, newY, cur+a[newX][newY], v);
			visited[newX][newY] = false;
			v.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
			sum += a[x][y];
		}
	}
	
	if(n % 2 == 0){
		cout << "1 1\n";
		for(int x=0;x<n;x++){
			if(x&1){
				for(int y=m-1;y>=1;y--){
					cout << x+1 << " " << y+1 << "\n";
				}
			} else {
				for(int y=1;y<m;y++){
					cout << x+1 << " " << y+1 << "\n";
				}
			}
		}
		for(int x=n-1;x>=1;x--){
			cout << x+1 << " " << 1 << "\n";
		}
	} else if(m % 2 == 0){
		cout << "1 1\n";
		for(int y=0;y<m;y++){
			if(y&1){
				for(int x=n-1;x>=1;x--){
					cout << x+1 << " " << y+1 << "\n";
				}
			} else {
				for(int x=1;x<n;x++){
					cout << x+1 << " " << y+1 << "\n";
				}
			}
		}
		for(int y=m-1;y>=1;y--){
			cout << 1 << " " << y+1 << "\n";
		}
	} else {
		cout << "-1\n";
	}
    return 0;
}

