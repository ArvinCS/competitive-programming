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

const int maxN = 1e6 + 5;

ll table[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans*x) % mod;
		
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

	int n, m, k;
	cin >> n >> m >> k;
	
	fill(table, table+n+1, 0);
	
	for(int x=1;x<k;x++) table[x] = m;
	for(int x=1;x<=n;x++){
		ll val = table[x-1] - (x-k >= 0 ? table[x-k] : 0ll);
		if(val < 0) val += mod;
		
		table[x] += (val * (m-1) % mod + table[x-1]) % mod;
		table[x] %= mod;
	}
	
	cout << (powmod(m, n) - ((table[n] - table[n-1] + mod) % mod) + mod) % mod << "\n";
    return 0;
}

