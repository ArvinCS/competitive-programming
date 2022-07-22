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

bool fair(ll n){
	bool valid = true;
	
	ll cur = n;
	while(cur > 0){
		ll digit = cur%10;
		if(digit > 0 && n % digit != 0){
			valid = false;
			break;
		}
		cur /= 10;
	}
	return valid;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		if(fair(n)){
			cout << n << "\n";
		} else {
			for(ull x=n;x<=n+sqrt(n);x++){
				if(fair(x)){
					cout << x << "\n";
					break;
				}
			}
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

