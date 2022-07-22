#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll powmod(ll x, ll y, ll z){
	ll ans = 1;
	
	x %= z;
	while(y > 0){
		if(y&1) ans = (ans * x) % z;
		
		y >>= 1ll;
		x = (x * x) % z;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll mod = 1000000007;
	ll a, b, c;
	while(true){
		cin >> a >> b >> c;
		
		if(a == b && b == c && a == -1) break;
		
		if(a%mod == 0){
			cout << "0\n";
			continue;
		}
		
		ll ans = powmod(a, powmod(b, c, mod-1), mod);
		cout << ans << "\n";
	}
    return 0;
}

