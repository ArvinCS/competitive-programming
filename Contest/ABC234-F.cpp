#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxL = 5e3 + 5;

ll fac[maxL], iv[maxL], cnt[27];

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
	
	string s;
	cin >> s;
	
	int n = s.length();
	fill(cnt, cnt+27, 0);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, mod-2);
	for(int x=2;x<maxL;x++){
		fac[x] = (x * fac[x-1]) % mod;
		iv[x] = powmod(fac[x], mod-2);
	}
	
	for(int x=0;x<n;x++){
		cnt[(s[x] - 'a')]++;
	}
	
	ll table[maxL], new_table[maxL];
	fill(table, table+maxL, 0);
	
	table[0] = 1;
	for(int x=0;x<26;x++){
		fill(new_table, new_table+maxL, 0);
		
		for(int y=1;y<=cnt[x];y++){
			for(int z=0;z<maxL;z++){
				if(z+y >= maxL) break;
				
				new_table[y+z] += table[z] * fac[z+y] % mod * iv[y] % mod * iv[z] % mod; 
				new_table[y+z] %= mod;
			}
		}
		
		for(int y=0;y<maxL;y++){
			table[y] += new_table[y];
			table[y] %= mod;
		}
	}
	
	ll ans = 0;
	for(int x=1;x<maxL;x++){
		ans += table[x];
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

