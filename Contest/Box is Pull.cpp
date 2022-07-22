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
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		ll ans = abs(x2-x1) + abs(y2-y1);
		if(x1 != x2 && y1 != y2) ans += 2;
		
		cout << ans << "\n";
	}
    return 0;
}

