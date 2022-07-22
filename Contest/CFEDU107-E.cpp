#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 3e5 + 50;

ll table[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
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
	
	table[0] = 0;
	table[1] = 1;
	
	ll cur = 1;
	for(ll x=2;x<maxN;x++){
		cur *= powmod(4, mod-2);
		cur %= mod;
		
		table[x] = (cur + table[x-1]) % mod;	
	}
	
	int n, m;
	cin >> n >> m;
	
	int white = 0;
	bool grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			char c;
			cin >> c;
			
			grid[x][y] = (c == 'o');
			white += grid[x][y];
		}
	}
	
	ll ans = 0;
	
	// horizontal dominoes
	for(int x=0;x<n;x++){
		ll cnt = 0;
		for(int y=0;y<m;y++){
			if(!grid[x][y]){
				cnt = 0;
				continue;
			}
			cnt++;
			
			if(y-1 >= 0 && grid[x][y-1] && grid[x][y]){
				if(cnt % 2 == 0){
					ans += powmod(powmod(2, 3), mod-2) * table[(cnt-2)/2] % mod;
					ans += powmod(powmod(2, cnt), mod-2);
				} else {
					ans += powmod(powmod(2, 3), mod-2) * table[1+(cnt-3)/2] % mod;	
				}
			}
			ans %= mod;
		}
	}
	
	// vertical dominoes
	for(int y=0;y<m;y++){
		ll cnt = 0;
		for(int x=0;x<n;x++){
			if(!grid[x][y]){
				cnt = 0;
				continue;
			}
			cnt++;
			
			if(x-1 >= 0 && grid[x-1][y] && grid[x][y]){
				if(cnt % 2 == 0){
					ans += powmod(powmod(2, 3), mod-2) * table[(cnt-2)/2] % mod;
					ans += powmod(powmod(2, cnt), mod-2);
				} else {
					ans += powmod(powmod(2, 3), mod-2) * table[1+(cnt-3)/2] % mod;
				}
			}
			ans %= mod;
		}
	}
	cout << ans*powmod(2, white) % mod << "\n";
    return 0;
}

