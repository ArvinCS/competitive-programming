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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a = 0, b = 0, c = 0;
	
	while(n--){
		ll tmp;
		cin >> tmp;
		
		tmp = abs(tmp);
		a += tmp;
		b += tmp * tmp;
		c = max(c, tmp);
	}
	
	cout << a << "\n";
	cout << fixed << setprecision(15) << sqrt(b) << "\n";
	cout << c << "\n";
	
    return 0;
}

