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
		ll n, k;
		cin >> n >> k;
		
		if(n & 1){
			ll sz = n/2;
			ll ans = (k + (k+sz-1)/sz - 1) % n;
			if(ans == 0) ans = n;
			cout << ans << "\n";
		} else {
			ll ans = k % n;
			if(ans == 0) ans = n;
			cout << ans << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

