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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll ans = -1;
		for(ll x=n;x<=n+100000;x++){
			ll sum = 0;
			ll tmp = x;
			while(tmp > 0){
				sum += tmp%10;
				tmp /= 10;
			}
			
			if(__gcd(sum, x) > 1){
				ans = x;
				break;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

