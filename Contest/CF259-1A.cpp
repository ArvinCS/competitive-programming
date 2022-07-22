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

	ll m, n;
	cin >> m >> n;
	
	double ans = 0;
	
	for(ll x=1;x<=m;x++){
		ans += x*(pow(x*1.0/m, n) - pow((x-1)*1.0/m, n));
	}
	
	cout << fixed << setprecision(4) << ans << "\n";

    return 0;
}

