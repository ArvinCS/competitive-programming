#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	ll n, l, r;
	cin >> n >> l >> r;
	
	ll ans = 0;
	for(int i=0;i<=59;i++){
		ll bit = (1ll << i);
		
		if(n&bit){
			ll val = n^bit;
			ans += max(0ll, min(r, 2ll*bit-1) - max(l, bit) + 1);
		}
	}
	cout << ans << "\n";
    return 0;
}

