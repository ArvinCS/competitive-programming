#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll l;
	cin >> n >> l;
	
	string s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	ll state[n];
	for(int x=0;x<n;x++){
		state[x] = 0;
		for(int y=0;y<s[x].length();y++){
			state[x] |= (1ll << (s[x][y] - 'a'));
		}
	}
	
	ll ans = 0;
	for(int row=1;row<(1 << n);row++){
		int len = __builtin_popcount(row)-1;
		ll cur = -1;
		for(int y=0;y<n;y++){
			if(row&(1 << y)){
				if(cur == -1) cur = state[y];
				cur &= state[y];
			}
		}
		
		ll val = powmod(__builtin_popcount(cur), l);
		if(len&1){
			ans -= val;
			if(ans < 0) ans += mod;
		} else {
			ans += val;
			if(ans >= mod) ans -= mod;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

