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
		
		bool possible = false;
		for(ll x=1;x*x*x<=n;x++){
			ll cnt1 = x*x*x;
			ll cnt2 = n-cnt1;
			
			if(cnt2 > 0){
				double tmp = cbrt(cnt2);
				if(ceil(tmp) == tmp){
					possible = true;
					break;
				}
			}
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

