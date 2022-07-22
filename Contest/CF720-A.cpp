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
	
	int t;
	cin >> t;
	
	while(t--){
		ll a, b;
		cin >> a >> b;
		
		if(b == 1){
			cout << "NO\n";
			continue;
		}
		
		ll ans1 = a, ans2 = 0, ans3 = -1;
		for(ll i=b;i<=b*100;i+=b){
			if(ans1 != (i-1)*a){
				ans2 = (i-1)*a;
				ans3 = ans1+ans2;
				break;
			}
		}
		if(ans3 == -1){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		cout << ans1 << " " << ans2 << " " << ans3 << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

