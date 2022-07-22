#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll dp[n], dp2[n];
	fill(dp, dp+n, 1e18);
	fill(dp2, dp2+n, 1e18);
	
	dp[0] = a[0];
	for(int x=1;x<n;x++){
		for(int y=x-1;y>=max(0, x-2);y--){
			dp[x] = min(dp[x], dp[y]+a[x]);
		}
	}
	
	dp2[1] = a[1];
	for(int x=2;x<n;x++){
		for(int y=x-1;y>=max(1, x-2);y--){
			dp2[x] = min(dp2[x], dp2[y]+a[x]);
		}
	}
	
	ll ans = min(dp[n-1], dp[n-2]);
	ans = min(ans, dp2[n-1]);
	
	cout << ans << "\n";
    return 0;
}

