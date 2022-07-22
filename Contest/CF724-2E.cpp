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

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
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
		
		int need = 0;
		char grid[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
				
				if(grid[x][y] == '#') need++;
			}
		}
		
		if(need == n*m){
			cout << (powmod(2, need)-1 + mod) % mod << "\n";
		} else {
			cout << powmod(2, need) << "\n";
		}
	}

    return 0;
}

