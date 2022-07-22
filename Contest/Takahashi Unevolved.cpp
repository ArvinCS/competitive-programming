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
	
	ull x, y, a, b;
	cin >> x >> y >> a >> b;
	
	ll ans = 0;
	
	while(x < b){
		if(x >= y){
			while(x >= y){
				x /= a;
				ans--;
			}
			break;
		}
		x *= a;
		ans++;
	}
	
	if(x >= y){
		while(x >= y){
			x /= a;
			ans--;
		}
	} else ans += (y - x - 1)/b;
	
	cout << ans << "\n";
    return 0;
}

