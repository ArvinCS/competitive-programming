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
	ll c;
	cin >> n >> m >> c;
	
	ll a[n][m];
	ll prefix[2][n][m]; // 0 from top left corner, 1 from bottom left corner
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> a[x][y];
		}
	}
	
	fill(*prefix[0], *prefix[2], -inf_ll);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(x-1 >= 0) prefix[0][x][y] = max(prefix[0][x-1][y], prefix[0][x][y]);
			if(y-1 >= 0) prefix[0][x][y] = max(prefix[0][x][y-1], prefix[0][x][y]);
			prefix[0][x][y] = max(prefix[0][x][y], (x+y+2)*c - a[x][y]);
		}
	}
	
	for(int x=n-1;x>=0;x--){
		for(int y=0;y<m;y++){
			if(x+1 < n) prefix[1][x][y] = max(prefix[1][x+1][y], prefix[1][x][y]);
			if(y-1 >= 0) prefix[1][x][y] = max(prefix[1][x][y-1], prefix[1][x][y]);
			prefix[1][x][y] = max(prefix[1][x][y], ((n-x)+(y+1))*c - a[x][y]);
		}
	}
	
	ll ans = inf_ll;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			ll best = -inf_ll, best2 = -inf_ll;
			if(x-1 >= 0){
				best = max(best, prefix[0][x-1][y]);
			}
			if(x+1 < n){
				best2 = max(best2, prefix[1][x+1][y]);
			}
			if(y-1 >= 0){
				best = max(best, prefix[0][x][y-1]);
				best2 = max(best2, prefix[1][x][y-1]);
			}
			
			ans = min(ans, (x+y+2)*c+a[x][y]-best);
//			cout << x << " -> " << ans << " 1\n";
			ans = min(ans, ((n-x)+y+1)*c+a[x][y]-best2);
//			cout << x << " -> " << ans << " 2\n";
		}
	}
	
	cout << ans << "\n";
    return 0;
}

