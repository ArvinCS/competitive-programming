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
	freopen("harta_6.in","r",stdin);
//	freopen("harta_3.out","w",stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	char grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	int ans = n*m;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y] == '#') ans--;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

