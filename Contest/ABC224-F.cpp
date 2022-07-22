#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 998244353

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	ll prefix[n];
	prefix[0] = (s[0] - '0');
	
	ll ans = 0, cnt = 1;
	for(int x=1;x<n;x++){
		ans += prefix[x-1] * powmod(2, n-x-1) % mod;
		ans %= mod;
		
		prefix[x] = (prefix[x-1] * 10 % mod + cnt * (s[x] - '0') % mod) % mod;
		
		prefix[x] += powmod(2, x-1) * (s[x] - '0') % mod;
		prefix[x] %= mod;
		
		cnt += powmod(2, x-1);
		cnt %= mod;
	}
	ans += prefix[n-1];
	ans %= mod;
	
	cout << ans << "\n";
    return 0;
}

