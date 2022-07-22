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
	
	ll n, k;
	cin >> n >> k;
	
	ll ans = 0;
	for(ll x=2;x<=2*n;x++){
		int need = x-k;
		if(need < 0) continue;
		for(int c=1;c<=n;c++){
			int d = need-c;
			if(d > 0 && d <= n){
				if(x != 2*n) ans += (x-1);
				else ans++;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

