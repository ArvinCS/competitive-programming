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
		int n;
		cin >> n;
		
		int lowA = inf_int, lowB = inf_int;
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			lowA = min(lowA, a[x]);
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
			lowB = min(lowB, b[x]);
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			ans += max(a[x]-lowA, b[x]-lowB);
		}
		cout << ans << "\n";
	}	

    return 0;
}

// Santai
// Pikirin dengan benar-benar

