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

const int maxN = 2e5 + 5;

ll table[2][maxN];
ll fac[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	x %= smod;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x * x) % smod;
	}
	return ans;
}

ll comb(ll a, ll b){
	if(b > a || b < 0) return 0;
	return ((fac[a] * powmod(fac[b], smod-2)) % smod * powmod(fac[a-b], smod-2)) % smod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % smod;
	}
	
	ll ans = 0;
	for(int x=1;x<=m;x++){
		table[0][x] = 1;
		ans++;
	}
	
	int length = 1;
	bool valid = true;
	while(valid){
		valid = false;
		for(int x=1;x<=m;x++){
			table[1][x] = 0;
		}
		
		for(int x=1;x<=m;x++){
			if(table[0][x] != 0){
				for(int y=x+x;y<=m;y+=x){
					valid = true;
					table[1][y] += table[0][x];
				}
			}
		}
		
		if(!valid) break;
		length++;
		for(int x=1;x<=m;x++){
			table[0][x] = table[1][x];
		}
		for(int x=1;x<=m;x++){
			ans += (table[0][x] * comb(n-1, length-1)) % smod;
			ans %= smod;
		}
	}
	
	cout << ans % smod << "\n";	

    return 0;
}

// Santai
// Pikirin dengan benar-benar

