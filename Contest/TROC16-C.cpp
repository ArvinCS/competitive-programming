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

ll modpow(ll x, ll y){
	ll ans = 1;
	x %= mod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll n, m;
	cin >> n >> m;
	
	ll table[n+5]; // last pos of m
	fill(table, table+n+5, 0);
	
	table[1] = 1;
	
	for(int x=2;x<=n+1;x++){
		for(int y=1;y+1<x;y++){
			table[x] += (table[y] * modpow(m-1, x-y-1)) % mod;
			table[x] %= mod;
		}
		if(x <= n) table[x] += modpow(m-1, x-1);
		table[x] %= mod;
	}
	
	cout << (table[n]+table[n+1]) % mod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

