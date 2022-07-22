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

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
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
	
	int n;
	cin >> n;
	
	ll table[n+1];
	fill(table, table+n+1, 0);
	
	table[1] = 1;
	for(int x=2;x<=n;x++){
		table[x] = x * table[x-1] % mod;
	}
	
	cout << table[n] << "\n";
    return 0;
}

