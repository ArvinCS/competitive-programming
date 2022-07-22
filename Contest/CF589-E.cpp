#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 256;

ll fac[maxN], iv[maxN], f[maxN][maxN];
ll fk1[maxN], fk2[maxN];

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

ll combin(ll n, ll r){
	if(n < r) return 0;
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	fac[0] = fac[1] = 1;
	fk1[0] = fk2[0] = 1;
	fk1[1] = k-1;
	fk2[1] = k;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
		fk1[x] = ((k-1) * fk1[x-1]) % mod;
		fk2[x] = (k * fk2[x-1]) % mod;
	}
	
	for(int r=1;r<=n;r++){
		f[r][0] = powmod((powmod(k, n) - powmod(k-1, n) + mod) % mod, r);
	}
	for(int c=1;c<=n;c++){
		f[1][c] = powmod(k, n-c);
	}
	
	for(int r=2;r<=n;r++){
		for(int c=1;c<=n;c++){
			f[r][c] = (fk2[n-c] - fk1[n-c] + mod) % mod * fk1[c] % mod * f[r-1][c] % mod;
			
			for(int c0=1;c0<=c;c0++){
				f[r][c] += fk2[n-c] * combin(c, c0) % mod * fk1[c-c0] % mod * f[r-1][c-c0] % mod;
				f[r][c] %= mod;
			}		
		}
	}
	
	cout << f[n][n] << "\n";
    return 0;
}

