#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b;
	cin >> a >> b;
	
	a %= mod;
	
	ll ans = 1;
	while(b > 0){
		if(b&1) ans = (ans * a) % mod;
		
		b >>= 1;
		a = (a * a) % mod;
	}
	
	cout << ans << "\n";
    return 0;
}

