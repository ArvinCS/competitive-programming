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

	int n, m;
	cin >> n >> m;
	
	char grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}

	ll table[n][m];
	fill(table[0], table[n], 0);
	
	table[0][0] = 1;
    for(int x=0;x<n;x++){
    	for(int y=0;y<m;y++){
    		if(grid[x][y] == '#') continue;
    		if(x+1 < n){
    			table[x+1][y] += table[x][y];
    			table[x+1][y] %= mod;
			}
    		if(y+1 < m){
    			table[x][y+1] += table[x][y];
    			table[x][y+1] %= mod;
			}
		}
	}
	
	cout << table[n-1][m-1] << "\n";
	return 0;
}

// Santai
// Pikirin dengan benar-benar

