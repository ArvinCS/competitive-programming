#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

us n, m;
char grid[2005][2005];

void solve(){
	us table[n][m];
	fill(table[0], table[n], 1);
	//dont tle
	for(us x=0;x<n-2;x++){
		for(us y=0;y<m-1;y++){
			if(grid[x][y] == grid[x+1][y] && grid[x][y] == grid[x+1][y-1] && grid[x][y] == grid[x+2][y] && grid[x][y] == grid[x+1][y+1]){
				table[x+2][y] = min(table[x][y], min(table[x+1][y], min(table[x+1][y-1], table[x+1][y+1]))) + 1;
			}
//			if(grid[x][y] == grid[x-1][y]){				
//				for(short prev=table[x-1][y];prev>=1;prev--){
//					if(x-2*prev < 0) continue;
//					
//					bool pass = true;
//					short start = x-2*prev, w = -1;
//					for(short i=0;i<2*prev+1;i++){
//						if(i <= prev) w++;
//						else w--;
////						cout << x << "-" << y << " -- " << i << "\n";
//						if(y-w < 0 || y+w >= m || grid[start+i][y-w] != grid[x][y] || grid[start+i][y+w] != grid[x][y]){
////							cout << "break2\n";
//							pass = false;
//							break;
//						}
//					}
//					
//					if(pass){
//						table[x][y]+=prev;
//						break;
//					}
//				}
//			}
		}
	}
	
	ll ans = 0;
	for(us x=0;x<n;x++){
		for(us y=0;y<m;y++){
			ans += table[x][y];
//			cout << table[x][y] << " ";
		}
//		cout << "\n";
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    	
    cin >> n >> m;
    
    for(us x=0;x<n;x++){
    	for(us y=0;y<m;y++){
    		cin >> grid[x][y];
		}
	}
	
	solve();
	
    return 0;
}

