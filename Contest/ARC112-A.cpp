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
	
	int t;
	cin >> t;
	
	while(t--){
		ll l, r;
		cin >> l >> r;
		
		ll ans = max(r-l-(l-1), 0ll);
		ans = (ans*(ans+1))/2;
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

