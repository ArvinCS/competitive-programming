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

ll mul(ll x, ll y){
	ll ans = 0;
	x %= mod;
	while(y > 0){
		if(y % 2 == 1) ans = (ans + x) % mod;
		
		x = (x * 2) % mod;
		y /= 2;
	}
	return ans % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n, m;
	cin >> n >> m;
	
	ll table[n+1][2];
	
	table[0][0] = 1;
	table[0][1] = 0;
	
	for(short x=1;x<=n;x++){
		table[x][0] = mul(m-1, table[x-1][0] + table[x-1][1]);
		table[x][1] = table[x-1][0];
	}
	
	ll rem = 1;
	for(short x=1;x<=n;x++){
		rem = mul(rem, m-1);
	}
	
	cout << max(table[n][0] - rem + table[n][1], 0ll) << "\n";
    return 0;
}

