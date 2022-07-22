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

const int maxN = 2 * 1e5 + 5;

ll table[maxN];

ll modpow(ll x, ll y){
	ll ans = 1;
	x %= smod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x * x) % smod;
	}
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
		
	int n;
	cin >> n;
	
	fill(table, table+n+1, 0);
	
	for(int x=n;x>=1;x--){
		table[x] += ((10 * (n-x > 0 ? 9 : 1) * (n-x-1 > 0 ? modpow(10, n-x-1) : 1)) % smod * (1 + (n-x > 0))) % smod;
		table[x] %= smod;
		
		if(n-x >= 2){
			ll tmp = (10 * 9 * 9 * (n-x-2 >= 1 ? modpow(10, n-x-2) : 1));
			
			table[x] += (tmp % smod * (n-x-1)) % smod;
		}
		
		table[x] %= smod;
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << table[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

