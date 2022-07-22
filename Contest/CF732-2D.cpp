#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

const int maxN = 1e5 + 5;

ll fac[maxN], iv[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}	
	return ans;
}

ll combin(ll x, ll y){
	return (fac[x] * iv[x-y] % mod * iv[y] % mod);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	for(ll x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int sum = 0;
		for(int x=0;x<n;x++){
			if(s[x] == '0'){
				sum++;
			}
		}
		
		int leftSpace = 0;
		ll cnt = 0, a = 0, b = 0;
		for(int x=0;x<n;x++){
			if(s[x] == '0'){
				if(cnt == 1) a++;
				
				leftSpace++;
				cnt = 0;
			} else {
				cnt++;
			}
			
			if(cnt == 2){
				b++;
				cnt = 0;
			}
		}
		if(cnt == 1){
			a++;
		}
				
		cout << combin(n-a-b, b) << "\n";
	}
	
    return 0;
}

