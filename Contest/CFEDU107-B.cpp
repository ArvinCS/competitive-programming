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

ll len(ll n){
	ll ans = 0;
	while(n > 0){
		ans++;
		n /= 10;
	}	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		
		ll cur = 2;
		while(len(cur) < c){
			cur *= 2ll;
		}
		
		ll ans1 = cur, ans2 = cur;
		while(len(ans1) < a){
			ans1 *= 2ll;
		}
		while(len(ans2) < b){
			ans2 *= 3ll;
		}
		
		cout << ans1 << " " << ans2 << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

