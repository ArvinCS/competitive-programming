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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}

		ll cnt[65];
		fill(cnt, cnt+65, 0);
		
		for(ll i=0;i<=60;i++){
			ll bit = (1ll << i);
			for(int x=0;x<n;x++){
				if((data[x]&bit)){
					cnt[i]++;
				}
			}
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			ll a = 0, b = 0;
			for(ll i=0;i<=60;i++){
				ll bit = (1ll << i);
				
				bool one = (data[x]&bit);
				
				ll tmp = (bit % mod * cnt[i] % mod) % mod;
				if(one) a += tmp;
				b += tmp + (one ? (bit % mod * (n-cnt[i]) % mod) % mod : 0ll);
				
				a %= mod;
				b %= mod;
			}
			ans += (a * b) % mod;
			ans %= mod;
//			cout << x << " -> " << a << " " << b << "\n";
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

