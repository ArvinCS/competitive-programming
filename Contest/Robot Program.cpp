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
		int x, y;
		cin >> x >> y;
		
		int ans = x+y;
		if(x != y) ans += max(x,y)-min(x,y)-1;
		
		cout << ans << "\n";	
	}
	
    return 0;
}

