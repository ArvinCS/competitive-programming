#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b, k;
	cin >> a >> b >> k;
	
	int ans = 0;
	while(a < b){
		ans++;
		a *= k;
	}
	
	cout << ans << "\n";
    return 0;
}

