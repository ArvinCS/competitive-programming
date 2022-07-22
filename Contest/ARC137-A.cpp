#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll l, r;
	cin >> l >> r;
	
	if(l+1 == r){
		cout << 1 << "\n";
		return 0;
	}
	
	ll ans1 = 0, ans2 = 0;
	for(ll x=r;x>=r-100;x--){
		if(l >= x) break;
		if(__gcd(l, x) == 1){
			ans1 = x-l;
			break;
		}
	}
	for(ll x=r;x>=r-100;x--){
		if(l+1 >= x) break;
		if(__gcd(l+1, x) == 1){
			ans2 = x-l-1;
			break;
		}
	}
	
	cout << max(ans1, ans2) << "\n";
    return 0;
}

