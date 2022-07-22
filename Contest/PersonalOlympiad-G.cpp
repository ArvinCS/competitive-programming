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
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	ll table[n][2];
	fill(table[0], table[n], 0);
	
	if(s[0] == '0'){
		table[0][1] = 2;
	} else {
		table[0][1] = 1;
		table[0][0] = 2;
	}
	
	for(int x=1;x<n;x++){
		if(s[x] == '0'){
			table[x][1] += 2*table[x-1][1] % mod;	
		} else {
			table[x][1] += table[x-1][1] % mod;
			table[x][0] += 2*table[x-1][1] % mod;	
		}
		if(table[x][1] >= mod) table[x][1] -= mod;
		if(table[x][0] >= mod) table[x][0] -= mod;
		
		table[x][0] += 3*table[x-1][0] % mod;
		
		if(table[x][0] >= mod) table[x][0] -= mod;
	}
	
	ll ans = (table[n-1][0] + table[n-1][1] - powmod(2, n) + mod) % mod;
	for(int x=1;x<n;x++){
		ans -= (powmod(2, x) - 1) * powmod(3, n-x-1) % mod;
		if(ans < 0) ans += mod;
	}
	
	cout << ans << "\n";
    return 0;
}

