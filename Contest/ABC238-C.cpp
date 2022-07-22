#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

ll mulmod(ll x, ll y){
	ll ans = 0;
	
	while(y > 0){
		if(y&1) ans = (ans + x) % mod;
		
		y >>= 1;
		x = (x+x) % mod;
	}
	return ans;
}

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
	
	ll n;
	cin >> n;
	
	ll ans = 0;
	for(ll x=1;x<=1e17;x*=10){
		ll mn = max(0ll, min(x*10-x, n-x+1));
		
		ans += mulmod(mn, (mn+1)) * powmod(2, mod-2) % mod;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

