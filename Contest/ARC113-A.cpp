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

	ll k;
	cin >> k;
	
	ll ans = 0;
	for(ll x=1;x<=k;x++){
		for(ll y=x;y<=k;y++){
			if(x*y > k) break;
			for(ll z=y;z<=k;z++){
				if(x*y*z > k) break;
				int tmp = 6;
				if(x == y || y == z || x == z) tmp = 3;
				if(x == y && y == z) tmp = 1;
				ans += tmp;
			}
		}
	}

	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

