#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int sz = 16;
const int state = 8;
const int mx = 8;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

void chadd(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll m;
		cin >> m;
		
		cout << ((m/4+1)%mod)*((m/2 - m/4 + 1)%mod) % mod << "\n";
	}
    return 0;
}

