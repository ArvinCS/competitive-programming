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
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(fac[1], mod-2);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll ans = (fac[2*n] * iv[2]) % mod;
		cout << ans << "\n";
	}
	
    return 0;
}

