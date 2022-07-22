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
	
	int n, m;
	cin >> n >> m;
	
	char a[n], b[m];
	for(int x=0;x<n;x++) cin >> a[x];
	for(int x=0;x<m;x++) cin >> b[x];
	
	int lcs[n+1][m+1];
	for(int x=0;x<=n;x++){
		lcs[x][0] = 0;
	}
	for(int x=0;x<=m;x++){
		lcs[0][x] = 0;
	}

	int ans = 0;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			if(x == 0 || y == 0){
				lcs[x][y] = 0;
			} else if(a[x-1] == b[y-1]){
				lcs[x][y] = lcs[x-1][y-1] + 2;
			} else {
				lcs[x][y] = max(0, max(lcs[x-1][y], lcs[x][y-1]) - 1);
			}
			ans = max(ans, lcs[x][y]);
		}
	}

	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

