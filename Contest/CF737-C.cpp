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

const int maxN = 2e5 + 5;

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

ll combin(int x, int y){
	return fac[x] * iv[x-y] % mod * iv[y] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	
	for(ll x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	us t;
	cin >> t;
	
	while(t--){
		ll n, k;
		cin >> n >> k;
		
		ll cnt = 1;
		for(int x=2;x<n;x+=2){
			cnt = (combin(n, x) + cnt) % mod;
		}
		if(n&1) cnt = (cnt+1) % mod;
		
		ll sum = 1, ans = 0;
		for(int x=0;x<k;x++){
			if(n % 2 == 0){
				ans += sum*powmod(2, (k-x-1)*n) % mod;
				ans %= mod;
			}
			
			sum *= cnt;
			sum %= mod;
		}
		ans += sum;
		ans %= mod;
		
		cout << ans << "\n";
	}

    return 0;
}

