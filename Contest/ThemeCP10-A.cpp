#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll k, a, b;
	cin >> k >> a >> b;
	
	if(a < k && b < k){
		cout << "-1\n";
		return 0;
	}
	if(a % k != 0 && b < k){
		cout << "-1\n";
		return 0;
	}
	if(a < k && b % k != 0){
		cout << "-1\n";
		return 0;
	}
	
	ll ans = a/k;
	ans += b/k;
	cout << ans << "\n";
	
    return 0;
}

