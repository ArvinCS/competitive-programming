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

const int maxN = 2 * 1e6 + 5;

ll prime[maxN];
ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=0;x<maxN;x++) prime[x] = x;
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=x+x;y<maxN;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	table[0] = table[1] = table[2] = 0;
	table[3] = table[4] = 4;
	
	for(ll x=5;x<maxN;x++){
		ll tmp = table[x-1];
		tmp += ((2ll * table[x-2]) % mod + (x % 3 == 0 ? 4 : 0)) % mod;
		table[x] = tmp % mod;
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		cout << table[n] << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

