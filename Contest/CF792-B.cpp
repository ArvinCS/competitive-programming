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
		ll a, b, c;
		cin >> a >> b >> c;
		
//		ll lcm = (a*1ll*b*c)/__gcd(a, __gcd(b, c));
//		ll mn = (a+b+a-1)/a;
		cout << 2*(c+b)+a << " " << c+b << " " << c << "\n";
	}
	
    return 0;
}

