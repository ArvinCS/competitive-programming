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
	
	ll n;
	cin >> n;
	
	ll ans = 2;
	for(ll x=3;x<=n;x++){
		ans = (ans*x)/__gcd(ans,x);	
	}
	
	cout << ans+1 << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

