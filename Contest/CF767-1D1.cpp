#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 2005;

ll table[maxN][maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll div2 = powmod(2, mod-2);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		ll k;
		cin >> n >> m >> k;
		
		for(int x=0;x<=n;x++){
			table[x][0] = 0;
		}
		for(int x=0;x<=min(n, m);x++){
			table[x][x] = x*k % mod;
		}
		
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				if(x == y) continue;
				
				table[x][y] = (table[x-1][y-1] + table[x-1][y]) % mod * div2 % mod;
			}
		}
		
		cout << table[n][m] << "\n";
	}
	
    return 0;
}

