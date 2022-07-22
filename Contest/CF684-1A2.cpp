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

const int maxSum = 1e6;

int grid[5000][5000];
pair<int, int> ans[maxSum];
pair<int, int> dir[4] = {{1, 1}, {0, 0}, {0, 1}, {1, 0}};

void change(int a, int b, int c, int d, int e, int f){
	grid[a][b] ^= 1;
	grid[c][d] ^= 1;
	grid[e][f] ^= 1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				char tmp;
				cin >> tmp;
				
				grid[x][y] = (tmp - '0');
			}
		}
		
		int idx = 0;
		
		for(int x=0;x<n-2;x++){
			for(int y=0;y<m-1;y++){
				if(grid[x][y] == 1 && grid[x][y+1] == 0){
					change(x, y, x+1, y, x+1, y+1);
					ans[idx++] = {x, y};
					ans[idx++] = {x+1, y};
					ans[idx++] = {x+1, y+1};
				} else if(grid[x][y] == 0 && grid[x][y+1] == 1){
					change(x, y+1, x+1, y, x+1, y+1);
					ans[idx++] = {x, y+1};
					ans[idx++] = {x+1, y};
					ans[idx++] = {x+1, y+1};
				} else if(grid[x][y] == 1 && grid[x][y+1] == 1){
					change(x, y, x, y+1, x+1, y+1);
					ans[idx++] = {x, y};
					ans[idx++] = {x, y+1};
					ans[idx++] = {x+1, y+1};
				}
			}
		}
		for(int y=0;y<m-2;y++){
			if(grid[n-2][y] == 1 && grid[n-1][y] == 0){
				change(n-2, y, n-2, y+1, n-1, y+1);
				ans[idx++] = {n-2, y};
				ans[idx++] = {n-2, y+1};
				ans[idx++] = {n-1, y+1};
			} else if(grid[n-2][y] == 0 && grid[n-1][y] == 1){
				change(n-1, y, n-2, y+1, n-1, y+1);
				ans[idx++] = {n-1, y};
				ans[idx++] = {n-2, y+1};
				ans[idx++] = {n-1, y+1};
			} else if(grid[n-2][y] == 1 && grid[n-1][y] == 1){
				change(n-2, y, n-1, y, n-1, y+1);
				ans[idx++] = {n-2, y};
				ans[idx++] = {n-1, y};
				ans[idx++] = {n-1, y+1};
			}
		}
		
		vector<pair<int, int>> zero, one;
		for(int i=0;i<4;i++){
			if(grid[n-2+dir[i].first][m-2+dir[i].second]) one.push_back({n-2+dir[i].first, m-2+dir[i].second});
			else zero.push_back({n-2+dir[i].first, m-2+dir[i].second});
		}
		
		if(one.size() > 0){
			if(one.size() == 1){
				//step1
				pair<int, int> tmp = one.back();
				one.pop_back();
				grid[tmp.first][tmp.second] = 0;
				ans[idx++] = tmp;
				
				while(zero.size() > 1){
					ans[idx++] = zero.back();
					grid[zero.back().first][zero.back().second] = 1;
					one.push_back(zero.back());
					zero.pop_back();
				}
				zero.push_back(tmp);
				
				//step2
				tmp = one.back();
				one.pop_back();
				grid[tmp.first][tmp.second] = 0;
				ans[idx++] = tmp;
				while(zero.size() > 0){
					ans[idx++] = zero.back();
					grid[zero.back().first][zero.back().second] = 1;
					one.push_back(zero.back());
					zero.pop_back();
				}
				zero.push_back(tmp);
				
				//step3
				while(one.size() > 0){
					ans[idx++] = one.back();
					grid[one.back().first][one.back().second] = 0;
					zero.push_back(one.back());
					one.pop_back();
				}
			} else if(one.size() == 2){
				// step 1
				ans[idx++] = one.back();
				grid[one.back().first][one.back().second] ^= 1;
				one.pop_back();
				
				while(zero.size() > 0){
					ans[idx++] = zero.back();
					grid[zero.back().first][zero.back().second] ^= 1;
					one.push_back(zero.back());
					zero.pop_back();
				}
				
				// step 2
				while(one.size() > 0){
					ans[idx++] = one.back();
					grid[one.back().first][one.back().second] ^= 1;
					one.pop_back();
				}
			} else if(one.size() == 3){
				// step 1
				while(one.size() > 0){
					ans[idx++] = {one.back().first, one.back().second};
					grid[one.back().first][one.back().second] ^= 1;
					zero.push_back(one.back());
					one.pop_back();
				}
			} else {
				// step1
				while(one.size() > 1){
					ans[idx++] = one.back();
					grid[one.back().first][one.back().second] = 0;
					zero.push_back(one.back());
					one.pop_back();
				}
				
				//step2
				pair<int, int> tmp = one.back();
				one.pop_back();
				grid[tmp.first][tmp.second] = 0;
				ans[idx++] = tmp;
				
				while(zero.size() > 1){
					ans[idx++] = zero.back();
					grid[zero.back().first][zero.back().second] = 1;
					one.push_back(zero.back());
					zero.pop_back();
				}
				zero.push_back(tmp);
				
//					//step3
				tmp = one.back();
				one.pop_back();
				grid[tmp.first][tmp.second] = 0;
				ans[idx++] = tmp;
				while(zero.size() > 0){
					ans[idx++] = zero.back();
					grid[zero.back().first][zero.back().second] = 1;
					one.push_back(zero.back());
					zero.pop_back();
				}
				zero.push_back(tmp);
				
				//step4
				while(one.size() > 0){
					ans[idx++] = one.back();
					grid[one.back().first][one.back().second] = 0;
					zero.push_back(one.back());
					one.pop_back();
				}
			}
		}
		
		cout << idx/3 << "\n";
		for(int x=0;x<idx;x+=3){
			cout << ans[x].first+1 << " " << ans[x].second+1 << " " << ans[x+1].first+1 << " " << ans[x+1].second+1 << " " << ans[x+2].first+1 << " " << ans[x+2].second+1 << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

