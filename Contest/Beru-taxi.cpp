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
	
	short a, b;
	cin >> a >> b;
	
	short n;
	cin >> n;
	
	double ans = 1000000000;
	for(short i=0;i<n;i++){
		int x, y, v;
		cin >> x >> y >> v;
		
		x = abs(a-x); y = abs(b-y);
		double time = sqrt(x*x + y*y) * 1.0/v;
		
		if(time < ans) ans = time;
	}
	
	cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

