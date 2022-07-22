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

ll table[2005][2005];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n, k;
		cin >> n >> k;
		
		fill(table[0], table[n+5], -1);
		
		for(int x=0;x<=2000;x++){
			table[x][0] = 0;
		}
		
		for(int y=1;y<=k;y++){
			table[n+1][y] = 1;
			for(int x=n;x>=1;x--){
				table[x][y] = (table[x+1][y] % mod + table[(n-x+1)+1][y-1] % mod) % mod;
			}
		}
		
		cout << table[1][k] << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

