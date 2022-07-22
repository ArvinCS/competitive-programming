#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 505;

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

ll combin(ll x, ll y){
	return fac[x] * iv[x-y] % mod * iv[y] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, m;
	cin >> n >> m;
	
	ll table[n+1][m+1];
	fill(table[0], table[n+1], 0);
	
	table[0][0] = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<=m;y++){
			for(int z=0;z<=m;z++){
				
			}
		}
	}
    return 0;
}

