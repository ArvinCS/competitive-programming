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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll ans = 0;
		ll cur = 1;
		for(ll x=2;x<=41;x++){
			ll lcm = (cur * x) / __gcd(cur, x);
			ll tmp = n/cur;
			tmp -= n/lcm;
			tmp %= mod;
			
			ans += (tmp*x) % mod;
			ans %= mod;
			cur = lcm;
		}
		
		cout << ans << "\n";
	}

    return 0;
}

