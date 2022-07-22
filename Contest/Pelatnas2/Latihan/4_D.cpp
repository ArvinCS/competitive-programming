#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int maxN = 355;

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

ll combin(int n, int r){
	if(n < r) return 0;
	
	return fac[n] * iv[n-r] % mod * iv[r] % mod;
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
	
	int n;
	cin >> n;
	
	ll table[n+1][n+1][2];
	fill(*table[0], *table[n+1], 0);
	
	table[0][n][0] = 1;
	for(int x=0;x<n;x++){
		for(int rem=0;rem<=n;rem++){
			for(int use=0;use<=rem;use++){
				bool ok = (use == x+1);
				
				if(ok){
					table[x+1][rem-use][1] += combin(rem, use) * (table[x][rem][0] + table[x][rem][1]) % mod;
					table[x+1][rem-use][1] %= mod;
				} else {
					table[x+1][rem-use][1] += combin(rem, use) * table[x][rem][1] % mod;
					table[x+1][rem-use][1] %= mod;
					
					table[x+1][rem-use][0] += combin(rem, use) * table[x][rem][0] % mod;
					table[x+1][rem-use][0] %= mod;
				}
			}
		}
	}
	
	
	cout << table[n][0][1] << "\n";
    return 0;
}

