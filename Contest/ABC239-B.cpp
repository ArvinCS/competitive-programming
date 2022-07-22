#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll x;
	cin >> x;
	
	ll ans = x/10;
	if(x % 10 != 0){
		if(x < 0){
			ans--;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

