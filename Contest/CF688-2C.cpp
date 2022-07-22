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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<pair<int, int>> v[10];
		int grid[n][n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				char c;
				cin >> c;
				
				grid[x][y] = (c - '0');
				v[grid[x][y]].push_back({x, y});
			}
		}
		
		vector<pair<int, int>> corner = {{0, 0}, {0, n-1}, {n-1, 0}, {n-1, n-1}};
		for(int d=0;d<10;d++){
			ll ans = 0;
			
			// 3 cases :
			// pick most far away point with parallel X.
			// pick most far away point with parallel Y.
			// pick most far away point wiht no parallel sides but we must change one of point that parallel.
			for(int x=0;x<v[d].size();x++){
				for(int y=x+1;y<v[d].size();y++){
					bool parallelX = (v[d][x].second == v[d][y].second);
					bool parallelY = (v[d][x].first == v[d][y].first);
					
					if(parallelX){
						ll length = abs(v[d][x].first-v[d][y].first);
						
						for(int z=0;z<corner.size();z++){
							if(corner[z].first <= min(v[d][x].first, v[d][y].first)){
								
							} else if(corner[z].first >= max(v[d][x].first, v[d][y].first)){
								
							}
						}
					} else if(parallelY){
						
					} else {
						
					}
				}
			}
			
			if(d > 0) cout << " ";
			cout << ans;
		}
		cout << "\n";
	}
	
    return 0;
}

