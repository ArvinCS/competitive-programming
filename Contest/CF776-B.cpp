#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll l, r, a;
		cin >> l >> r >> a;
		
		ll mx = (r+1)/a;
		ll val = max(l, mx*a - 1);
		ll val2 = r;
		cout << max(val/a + val%a, val2/a + val2%a) << "\n";
	}
	
    return 0;
}

