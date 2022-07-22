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
		if(b % 2) ans = (ans + a) % smod;
		
		a = (a*2) % smod;
		b /= 2;
		
		ans %= smod;
	}
	
	return ans % smod;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ull a, b, c;
	cin >> a >> b >> c;
	
	ull cntA = (a*(a+1)/2) % smod, cntB = (b*(b+1)/2) % smod, cntC = (c*(c+1)/2) % smod;
	
	cout << mul(cntA, mul(cntB, cntC)) << "\n";
    return 0;
}

