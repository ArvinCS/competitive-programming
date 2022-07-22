#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ll gcd(ll a, ll b){
	if(a == 0) return b;
	return gcd(b%a, a);	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	ll lowest = 0;
	for(ui x=0;x<n;x++){
		ll tmp;
		cin >> tmp;
		lowest = gcd(lowest, tmp);
	}

	us ans = 0;
	for(ui x=1;x*1ll*x<=lowest;x++){
		if(lowest % x == 0){
			ans += 1 + (lowest/x != x);
		}	
	}
	
	cout << ans << "\n";
    return 0;
}
