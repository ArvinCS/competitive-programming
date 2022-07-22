#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll m, a, d, n;
	cin >> m >> a >> d >> n;
	
	if(d == 0){
		cout << abs(m-a) << "\n";	
		return 0;
	}
	
	ll dif = (m-a)/d;
	
	ll ans = min(abs(m-a), abs(m-(a+(n-1)*d)));
	if(dif >= 1 && dif <= n){
		ans = min(ans, abs(m-(a+(dif-1)*d)));
	}
	if(dif+1 >= 1 && dif+1 <= n){
		ans = min(ans, abs(m-(a+dif*d)));
	}
	if(dif+2 >= 1 && dif+2 <= n){
		ans = min(ans, abs(m-(a+(dif+1)*d)));
	}
	
	cout << ans << "\n";
    return 0;
}

