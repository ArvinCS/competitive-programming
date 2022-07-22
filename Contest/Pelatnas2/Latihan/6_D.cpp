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
	
	int a[n+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	
	ll div2 = powmod(2, mod-2);
	
	ll prefix[n+1], iv[n+1];
	prefix[0] = a[0];
	iv[0] = powmod(prefix[0], mod-2);
	for(int x=1;x<=n;x++){
		prefix[x] = a[x] * prefix[x-1] % mod;
		iv[x] = powmod(prefix[x], mod-2);
	}
	
	ll table[2][2*n+1], ans[2*n+1];
	fill(ans, ans+2*n+1, 0);
	
	for(int x=0;x<=n;x++){
		table[x&1][0] = 1;
		for(int y=1;y<=2*n;y++){
			table[x&1][y] = 0;
			
			if(x+y-1 <= n) table[x&1][y] += ((a[x] - 1) * prefix[x+y-1] % mod * iv[x] % mod * div2 % mod);
			if(x > 0 && y > 0) table[x&1][y] += table[(x&1)^1][y-1];
			if(table[x&1][y] >= mod) table[x&1][y] -= mod;
			
			if(x > 0){
				ans[y] += prefix[x-1] * table[(x&1)^1][y-1] % mod;
				if(ans[y] >= mod) ans[y] -= mod;
			}
		}
	}
	
	for(int x=1;x<=2*n;x++){
		if(x > 1) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}
