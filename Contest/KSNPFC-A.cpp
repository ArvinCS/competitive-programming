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

int dX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dY[8] = {1, 1, 1, 0, 0, -1, -1, -1};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	cin >> n;
	
	int grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c - '0');
		}
	}
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(!grid[x][y]) continue;
			
			for(int z=0;z<8;z++){
				int newX = x+dX[z], newY = y+dY[z];
				if(0 <= newX && newX < n && 0 <= newY && newY < n){
					if(grid[newX][newY]){
						v.push_back({x, y});
						break;
					}
				}
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for(auto p : v){
		cout << p.first << " " << p.second << "\n";
	}
    return 0;
}

