#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	if(n <= k){
		cout << n << "\n";
	} else {
		ll ans = pow(2ll, n-k) * k;
		cout << ans << "\n";
	}
	
    return 0;
}

