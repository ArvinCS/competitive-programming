#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	ll d;
	cin >> n >> m >> d;
	
	for(ll x=m;x<=max(n, m);x++){
		ll val = 0;
		
		if(x == m){
			val = x*1ll*(x+1)/2;
		} else {
			val = x*1ll*(x+1) - x - m*1ll*(m-1)/2;
		}
		
		if(val > d){
			break;
		}
		
		ll cnt = 2*x - 1 - (m-1) + (d-val)/x + ((d-val)%x != 0);
		
		if(cnt <= n){
			cout << "YES\n";
			return 0;
		}
	}
	
	cout << "NO\n";
    return 0;
}

