#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 2e5 + 5;

ll fac[maxN], iv[maxN];
ll table[maxN];

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

ll comb(ll n, ll r){
	if(n < r) return 0;
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
}

ll perm(ll n, ll r){
	if(n < r) return 0;
	return fac[n] * iv[n-r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	table[1] = 1;
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		table[x] = (fac[x] + table[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, m;
	cin >> n >> m;
	
	int d[n];
	for(int x=0;x<n;x++){
		cin >> d[x];
	}
	
	sort(d, d+n);
	
	ll prefix[n];
	prefix[0] = d[0];
	for(int x=1;x<n;x++){
		prefix[x] = (d[x] + prefix[x-1]) % mod;
	}
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		int idx = lower_bound(d, d+n, b) - d;
		int cnt = n-idx;
		
		if(cnt < a){
			cout << "0\n";
		} else {
			int rem = cnt-a;
			
			ll ans = (rem > 0 ? (comb(cnt-1, a) * fac[a] % mod * fac[cnt-a] % mod * comb(n, cnt) % mod * fac[n-cnt] % mod) * powmod(fac[n], mod-2) % mod * ((prefix[n-1] - (idx > 0 ? prefix[idx-1] : 0) + mod) % mod) % mod : 0);
			ans += (cnt < n ? (fac[cnt] * (cnt-a+1) % mod * comb(n, cnt+1) % mod * fac[n-cnt-1] % mod) % mod * powmod(fac[n], mod-2) % mod * (idx > 0 ? prefix[idx-1] : 0) % mod : 0);
			
			cout << ans % mod << "\n";
		}
	}
    return 0;
}

