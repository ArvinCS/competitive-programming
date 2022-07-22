#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	ll a = 0, b = 0, c = 0, var = 1;
	for(int x=0;x<n;x++){
		if(s[x] == 'a'){
			a += var;
			a %= mod;
		} else if(s[x] == 'b'){
			b += a;
			b %= mod;
		} else if(s[x] == 'c'){
			c += b;
			c %= mod;
		} else { // ?
//			var *= 3;
			c = (3*c + b) % mod;
			b = (3*b + a) % mod;
			a = (3*a + var) % mod;
//			var = (var + 1);
			var *= 3;
			var %= mod;
		}
//		cout << a << " | " << b << " | " << c << " | " << var << "\n";
	}
	
	cout << c << "\n";
	
    return 0;
}

