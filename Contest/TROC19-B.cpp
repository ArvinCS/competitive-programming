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

ll mul(ll a, ll b){
	ll ans = 0;
	a %= smod;
	while(b > 0){
		if(b & 1) ans = (ans + a) % smod;
		
		a = (a * 2) % smod;
		b /= 2;
	}
	return ans % smod;
}

ll power(ll a, ll b){
	ll ans = 1;
	while(b > 0){
		if(b&1) ans = (ans*a) % smod;
		
		b >>= 1;
		a = (a*a) % smod;
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	
	cout << power(2, mul(n,m)-1)<< "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

