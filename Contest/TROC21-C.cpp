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

const int maxN = 1e5 + 5;

ll fac[maxN];

ll powmod(ll a, ll b){
	ll ans = 1;
	a %= mod;
	
	while(b > 0){
		if(b&1) ans = (ans * a) % mod;
		
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	ll n, m;
	cin >> n >> m;
	
	cout << ((powmod(m, n) - powmod(m, n-1) + mod) % mod + m) % mod;
    return 0;
}

// Santai
// Pikirin dengan benar-benar

