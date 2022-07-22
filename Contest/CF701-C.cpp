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
		ll a, b;
		cin >> a >> b;
		
		ll ans = 0;
		ll left = 2, right = min(a,b), point = -1;
		while(left <= right){
//			cout << left << " " << right << "\n";
			ll mid = (left+right)/2;
			ll cnt = min(a/(mid+1), mid-1);
//			cout << "res: " << cnt << "\n";
			if(cnt == mid-1){
				left = mid+1;
				point = mid;
			} else {
				right = mid-1;
			}
		}
		if(point != -1) ans += max((point-1)*point/2, 0ll);
//		cout << "cur: " << point << " , " << ans << "\n";
		ll cur = point+1;
		
		for(ll x=point-1;x>=1;x--){
			ll prev = ans;
			ans += max(min(a/x, b+1) - cur, 0ll) * x;
			cur = min(a/x, b+1);
//			cout << cur << " , " << x << " - " << ans << "\n";
			if(cur > b) break;
		}
		
//		for(ll x=max(point+1, 2ll);x<=min(a,b);x++){
//			ll cnt = min(a/(x+1), x-1);
//			cout << x << " -> " << cnt << "\n";
//			if(cnt == 0){
//				break;
//			} else {
//				ans += cnt;
//			}
//		}
	
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

