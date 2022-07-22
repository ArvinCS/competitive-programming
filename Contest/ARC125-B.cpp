#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll ans = 0;
	for(ll x=1;x*x<=n;x++){
		ll p = n/x;
		
		ans += (p-x+2)/2;
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

