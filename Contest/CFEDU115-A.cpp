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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		bool grid[2][n];
		for(int x=0;x<2;x++){
			for(int y=0;y<n;y++){
				char c;
				cin >> c;
				
				grid[x][y] = (c == '1');
			}
		}
		
		bool possible = true;
		for(int x=0;x<n;x++){
			if(grid[0][x] && grid[1][x]){
				possible = false;
				break;
			}
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

