#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define smod 998244353

ll powmod(ll x, ll y, ll mod){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

ll calc(ll a, ll k, ll m){
	if(k == 0) return 0;
	if(k == 1) return a;
	if(k % 2 == 1){
		return (calc(a, k-1, m) + powmod(a, k, m)) % m;
	} else {
		ll tmp = (calc(a, k/2, m));
		ll tmp2 = powmod(a, k/2, m);
		
		return (tmp * tmp2 % m + tmp) % m;
	}
}

ll f(ll a, ll b, ll c, ll x, ll k){
	ll ans = calc(a, k-1, c) + 1;
	ans %= c;
	ll tmp = (ans*b % c + powmod(a, k, c)*x % c + c) % c;
	
	return tmp;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		ll a, b, c, x, k;
		cin >> a >> b >> c >> x >> k;
		
		if(k == 1){
			cout << abs((a * x % c + b)) % c << "\n";
			continue;
		}
		if(a < 0){
			a *= -1;
			b *= -1;
		}		
		
		ll tmp1 = f(a, b, c, x, k), tmp2 = f(abs(a), abs(b), c, x, k);
		
		if((a < 0 && b > 0) || (a > 0 && b < 0)){
			if(tmp1 == tmp2) tmp1 = c-abs(tmp1);
		}
		cout << tmp1 << "\n";
	}
	
    return 0;
}

