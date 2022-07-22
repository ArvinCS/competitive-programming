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
		int n, m;
		cin >> n >> m;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll gcd = 0;
		for(int x=0;x<m;x++){
			ll val;
			cin >> val;
			
			gcd = __gcd(val, gcd);
		}
		
		if(gcd == 1){
			ll ans = 0;
			for(int x=0;x<n;x++){
				ans += abs(a[x]);
			}
			
			cout << ans << "\n";
			continue;
		}
		
		ll ans = 0, ans2 = 0;
		ll cnt[gcd];
		int odd[gcd], mx[gcd];
		fill(cnt, cnt+gcd, 0);
		fill(odd, odd+gcd, 0);
		fill(mx, mx+gcd, -2e9);
		
		for(int x=0;x<n;x++){
			if(a[x] < 0){
				mx[x%gcd] = max(mx[x%gcd], 2*a[x]);
				odd[x%gcd]++;
			} else {
				mx[x%gcd] = max(mx[x%gcd], -2*a[x]);
			}
			
			cnt[x%gcd] += abs(a[x]);
		}
		
		for(int x=0;x<gcd;x++){
			if(odd[x] % 2 == 0){
				ans += cnt[x];
			} else {
				ans += cnt[x]+mx[x];					
			}
		}
		
		for(int x=0;x<gcd;x++){
			odd[x] ^= 1;
			if(odd[x] % 2 == 0){
				ans2 += cnt[x];
			} else {
				ans2 += cnt[x]+mx[x];					
			}
		}
		
		cout << max(ans, ans2) << "\n";
	}
    return 0;
}

