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

const int maxN = 5e5 + 5;

ll fac[maxN];
bool prime[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	x %= smod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;		
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, k;
	cin >> n >> k;
	
	if(k > n){
		cout << "0\n";
		return 0;
	}
	
	if(k == 1){
		cout << n << "\n";
		return 0;
	}
	
	fill(prime, prime+n+1, true);
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<=n;x++){
		fac[x] = (x * fac[x-1]) % smod;
	}
	
	ll ans = ((fac[n-1] * powmod(fac[n-1-(k-1)], smod-2)) % smod * powmod(fac[k-1], smod-2)) % smod;
	for(ll x=2;x*k<=n;x++){
		ll num = n/x;
		if(num < k){
			break;
		}
		
		ll tmp = ((fac[num-1] * powmod(fac[num-1-(k-1)], smod-2)) % smod * powmod(fac[k-1], smod-2)) % smod;
		
		ans = (ans + tmp) % smod;
	}
	cout << ans % mod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

