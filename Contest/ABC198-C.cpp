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

	ll n, x, y;
	cin >> n >> x >> y;
	
	if((x*x) + (y*y) < (n*n)){
		cout << "2\n";
		return 0;
	}
	
	ll num = ((x*x) + (y*y) + (n*n) - 1)/(n*n);
	ll ans = ceil(sqrt(num));
	
	cout << ans << "\n";

    return 0;
}

// Santai
// Pikirin dengan benar-benar

