#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 2e5 + 5;

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

ll combin(ll n, ll r){
	if(n < r) return 0;
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, m;
	cin >> n >> m;
	
	ll ans = 0;
	for(int x=1;x<m;x++){
		ans += (combin(m-1, n-2) - combin(x-1, n-2) + mod) % mod * 1ll * powmod(2, n-3) % mod;
		if(ans >= mod) ans -= mod;
	}
	
	cout << ans % mod << "\n";
    return 0;
}

