#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll n, k;
		cin >> n >> k;
		
		if(n == 1){
			cout << "0\n";
			continue;
		}
		
		ll left = 1, right = 1e10;
		ll mx = right;
		
		while(left <= right){
			ll mid = (left+right)/2ll;
			
			ll val = 1 + (mid*(mid+1ll)/2ll);
			
			if(val >= n){
				mx = min(mx, mid);
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		ll ans = mx;
		ll val = mx*(mx+1ll)/2ll;
		val++;
		
		ll rem = n - val;
		if(rem > 0){
			ans += (rem+mx-1)/mx;
		}
		
//		cout << mx << " " << rem << " " << ((rem/mx) + (rem%mx > 0 ? 1 : 0)) << " " << (1 + (mx*(mx+1)/2)) << "\n";
		cout << ans << "\n";
	}
    return 0;
}

