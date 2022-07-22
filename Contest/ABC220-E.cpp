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
		if(y&1) ans = (ans*x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, d;
	cin >> n >> d;
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(x+d < n){
			ans += powmod(2, d);
			ans %= smod;
		}
		
		ll div = min(d, (n-1)-x);
		if(div >= 2){
			ans += powmod(2, div-2);
			ans %= smod;
		}
		cout << x << " -> " << ans << "\n";
	}
	cout << ans << "\n";
    return 0;
}

