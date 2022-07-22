#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

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
	cin >> n;
	
	ll a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	
	ll cnt[n+1];
	cnt[0] = 1;
	for(int x=1;x<=n;x++){
		cnt[x] = (cnt[x-1] * a[x-1]) % mod;
	}
	
	ll prefix[n+1];
	prefix[0] = a[0];
	for(int x=1;x<=n;x++){
		prefix[x] = a[x] * prefix[x-1] % mod;
	}
	
	ll div2 = powmod(2, mod-2);
	for(int x=1;x<=2*n;x++){
		ll ans = 0;
		for(int y=n;y>=0;y--){
			for(int z=y-1;z>=0;z--){
				int rem = x-(y-z);
				if(rem < 0) break;
				if(rem > 0){
					if(z+rem-1 <= n){
						ll val = cnt[y] * (a[z]-1) % mod;
						for(int i=z+1;i<z+rem;i++){
							val *= a[i];
							val %= mod;
						}
						
						ans += val * div2 % mod;
					}
				} else {
					ans += cnt[y];
				}
				
				if(ans >= mod) ans -= mod;
			}
			
//			if(ans >= mod) ans -= mod;
		}	
		
		if(x > 1) cout << " ";
		cout << ans;
	}
	cout << "\n";
    return 0;
}

