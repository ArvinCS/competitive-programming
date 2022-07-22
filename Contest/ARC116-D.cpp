#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

int n, m;
ll fac[5005], iv[5005], table[30][5005];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

ll combin(ll p, ll r){
	return fac[p] * iv[p-r] % mod * iv[r] % mod;
}

ll solve(int i, ll val){
	if(table[i][val] != -1) return table[i][val];
	if(i == 0){
		if(val <= n){
			return (val % 2 == 0 ? combin(n, val) : 0);
		} else {
			return 0;
		}
	}
	
	ll bit = (1 << i);
	ll ans = 0;
	for(int x=0;x<=n;x+=2){
		if(x*bit > val) break;
		
		ans += solve(i-1, val-x*bit) * combin(n, x) % mod;
		ans %= mod;
	}
	return table[i][val] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(int x=2;x<5005;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	fill(table[0], table[30], -1);
	
	cin >> n >> m;
	
	cout << solve(15, m) << "\n";
    return 0;
}

