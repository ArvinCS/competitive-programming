#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll ans = 0;
	for(ll a=1;a*a*a<=n;a++){
		for(ll b=a;a*b*b<=n;b++){
			ll c = n/(a*b);
			ans += max(0ll, c-b+1);
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}

