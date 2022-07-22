#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
//	ll tmp1 = 0, tmp2 = 0;
	ll ans = 0;
	ll tmp = 0, tmp2 = 0;
	for(ll x=1;x<=n;x++){
		ans += ((x*m)^m) % mod;
		tmp += x*m;
		tmp2 += (x*m)&m;
		if(ans >= mod) ans -= mod;
		if(x <= n) cout << x << " -> " << ans << " " << ((x*m)&m) << " " << (((x*m)&m)^m) << " " << ((x*m)^m) << "\n";
//		if(x >= 8){
//			tmp1 += x*(m % mod) % mod;
//			if(tmp1 >= mod) tmp1 -= mod;
//			
//			tmp2 += m;
//			if(tmp2 >= mod) tmp2 -= mod;
//		}
	}
	
//	cout << ans << " " << tmp1 << " " << tmp2 << "\n";
	cout << ans << " " << tmp << " " << tmp2 << "\n";
	return 0;
}
