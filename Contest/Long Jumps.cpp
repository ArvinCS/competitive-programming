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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll table[n], a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			table[x] = a[x];
		}
		
		ll ans = 0;
		for(int x=n-1;x>=0;x--){
			if(x+a[x] < n) table[x] += table[x+a[x]];
		}
		
		for(int x=0;x<n;x++) ans = max(ans, table[x]);
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

