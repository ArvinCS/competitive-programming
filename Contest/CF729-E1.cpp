#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define smod 998244353

const int maxN = 505;

ll combin[maxN][maxN], fac[maxN];
ll table[2][maxN*maxN];
ll n, mod;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n >> mod;
	
	fill(combin[0], combin[maxN], 0);
	fac[0] = 1;
	for(int x=0;x<maxN;x++){
		combin[x][0] = 1;
	}
	for(int x=1;x<maxN;x++){
		fac[x] = (x * 1ll * fac[x-1]) % mod;
		for(int y=1;y<=x;y++){
			combin[x][y] = (combin[x-1][y-1] + combin[x-1][y]) % mod;	
		}
	}
	
	fill(table[0], table[2], 0);
	for(int x=0;x<maxN*maxN;x++) table[0][x] = 1;
	
	ll ans = 0;
	for(int x=1;x<=n;x++){
		for(int y=0;y<maxN*maxN;y++){
			ll val = 0;
			for(int z=1;z<=x;z++){
				if(z > 1 && y-z+1 >= 0){
					ans += (table[0][y-z+1] - (y-z+1 > 0 ? table[0][y-z] : 0) + mod) % mod * val % mod * combin[n][x] % mod * fac[n-x] % mod;
					ans %= mod;
				}
				
				val += table[0][maxN*maxN-1];
				if(val >= mod) val -= mod;
				if(y-z+1 >= 0) val -= table[0][y-z+1];
				if(val < 0) val += mod;
			}
			
			table[1][y] = table[0][y];
			if(y >= x) table[1][y] = (table[1][y] - table[0][y-x] + mod) % mod;
			
			if(y > 0) table[1][y] += table[1][y-1];
			table[1][y] %= mod;
		}
		swap(table[0], table[1]);
	}
	
	cout << ans << "\n";
    return 0;
}

