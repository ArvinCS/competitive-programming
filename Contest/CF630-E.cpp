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

ll powmod(ll x, ll y){
	ll ans = 1;

	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x * x) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, m, l, r;
	cin >> n >> m >> l >> r;
	
	if(n*m % 2 == 1){
		cout << powmod(r-l+1, n*m) << "\n";
	} else {
		bool odd = ((r-l+1) % 2ll == 1);
		ll ans = (powmod(r-l+1, n*m)+(odd ? 1 : 0)+smod) % smod * powmod(2, smod-2) % smod;
		
		cout << ans % smod << "\n";	
	}
    return 0;
}

