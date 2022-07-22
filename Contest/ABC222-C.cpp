#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	char grid[2*n][m];
	for(int x=0;x<2*n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	int win[2*n];
	fill(win, win+2*n, 0);
	
	for(int x=0;x<m;x++){
		vector<pair<int, int>> v;
		for(int y=0;y<2*n;y++){
			v.push_back({-win[y], y});
		}
		
		sort(v.begin(), v.end());
		
		for(int y=0;y<2*n;y+=2){
			int p1 = v[y].second, p2 = v[y+1].second;
			
			if(grid[p1][x] == 'G'){
				if(grid[p2][x] == 'C'){
					win[p1]++;
				} else if(grid[p2][x] == 'P'){
					win[p2]++;
				}
			} else if(grid[p1][x] == 'C'){
				if(grid[p2][x] == 'P'){
					win[p1]++;
				} else if(grid[p2][x] == 'G'){
					win[p2]++;
				}
			} else if(grid[p1][x] == 'P'){
				if(grid[p2][x] == 'G'){
					win[p1]++;
				} else if(grid[p2][x] == 'C'){
					win[p2]++;
				}
			}
		}
	}
	
	vector<pair<int, int>> v;
	for(int y=0;y<2*n;y++){
		v.push_back({-win[y], y});
	}
	
	sort(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		cout << v[x].second+1 << "\n";
	}
    return 0;
}

