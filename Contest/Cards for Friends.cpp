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
	
	us t;
	cin >> t;
	
	while(t--){
		ull w, h, n;
		cin >> w >> h >> n;
		
		ull a = 1, b = 1;
		while(w > 0 && w%2 == 0){
			a *= 2;
			w /= 2;
		}
		while(h > 0 && h%2 == 0){
			b *= 2;
			h /= 2;
		}
		
		cout << (a*b >= n ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

