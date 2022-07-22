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
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	ll zero = 0, one = 0;
	ll ans = 0;
	
	for(int x=0;x<s.length();x++){
		if(s[x] == '1'){
			ans += zero * powmod(2, s.length()-x-1) % mod;
			ans %= mod;
			
			one += powmod(2, x);
			one %= mod;
		} else {
			ans += one * powmod(2, s.length()-x-1) % mod;
			ans %= mod;
			
			zero += powmod(2, x);
			zero %= mod;
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}

