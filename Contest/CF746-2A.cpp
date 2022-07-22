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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		ll h;
		cin >> n >> h;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		ll mx1 = a[n-1], mx2 = a[n-2];
		ll ans = h/(mx1+mx2);
		
		h -= ans*(mx1+mx2);
		ans *= 2;
		
		if(h > 0){
			h -= mx1;
			ans++;
		}
		if(h > 0){
			h -= mx2;
			ans++;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

