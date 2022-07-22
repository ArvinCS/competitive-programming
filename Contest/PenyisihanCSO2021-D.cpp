#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 105;
const ll mod = 998244353;

ll fac[maxN], iv[maxN];

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

ll combin(ll p, ll r){
	if(p < r) return 0ll;
	return fac[p] * iv[p-r] % mod * iv[r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int p, q, n;
	cin >> p >> q >> n;
	
	ll table[n+1][p+1][q+1];
	fill(*table[0], *table[n+1], 0);
	
	table[0][0][0] = 1;
	for(int x=1;x<=n;x++){
		for(int l=0;l<=p;l++){
			for(int r=0;r<=q;r++){
				for(int z=1;z<=p-l;z++){
					table[x][l+z][r] += table[x-1][l][r] * combin(p-l, z) % mod;
					table[x][l+z][r] %= mod;
				}
				for(int z=2;z<=q-r;z++){
					table[x][l][r+z] += table[x-1][l][r] * combin(q-r, z) % mod;
					table[x][l][r+z] %= mod;
				}
			}
		}
	}
	
	cout << table[n][p][q] * iv[n] % mod << "\n";
	return 0;
}
