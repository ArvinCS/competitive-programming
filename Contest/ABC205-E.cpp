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

const int maxN = 2e6 + 5;

ll fac[maxN];

ll powmod(ll a, ll b){
	ll ans = 1;
	
	while(b > 0){
		if(b&1) ans = (ans*a) % mod;
		
		b >>= 1;
		a = (a*a) % mod;
	}
	return ans;
}

ll comb(ll n, ll r){
	if(n < r) return 0;
	
	return fac[n] * powmod(fac[n-r], mod-2) % mod * powmod(fac[r], mod-2) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	if(n > m+k){
		cout << "0\n";
		return 0;
	}
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
	}
	
	cout << (comb(n+m, n) - comb(n+m, m+k+1) + 2ll*mod) % mod << "\n";
    return 0;
}



