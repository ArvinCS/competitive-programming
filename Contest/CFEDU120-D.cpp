#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int maxN = 5e3 + 5;
const ll mod = 998244353;

ll fac[maxN], iv[maxN];

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

ll combin(ll p, ll r){
	if(p < r) return 0ll;
	return fac[p] * iv[p-r] % mod * iv[r] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	for(int x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int cnt = 0;
	for(int x=0;x<n;x++){
		cnt += (s[x] - '0');
	}
	
	if(k == 0 || cnt < k){
		cout << "1\n";
		return 0;
	}
	
	ll ans = 1;
	for(int l=0;l<n;l++){
		int zero = 0, one = 0;
		for(int r=l;r<n;r++){
			if(s[r] == '1') one++;
			else zero++;
			
			if(one > 0 && zero > 0 && one <= k){
				if(l < r && s[l] == '0' && s[r] == '0'){
					ans += combin(zero+one-2, zero);
				} else if(s[l] == '0'){
					ans += combin(zero+one-2, zero-1);
				} else if(s[r] == '0'){
					ans += combin(zero+one-2, zero-1);
				} else {
					ans += combin(zero+one-2, zero-2);
				}
				
				if(ans < 0) ans += mod;
				if(ans >= mod) ans -= mod;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}
