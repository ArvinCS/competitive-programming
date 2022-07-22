#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	ll dp[n][3005];
	fill(dp[0], dp[n], 0);
	
	for(int x=a[0];x<=b[0];x++){
		dp[0][x]++;
	}
	
	for(int x=1;x<n;x++){
		ll sum = 0;
		for(int y=0;y<=3000;y++){
			sum += dp[x-1][y];
			sum %= mod;
			
			if(a[x] <= y && y <= b[x]){
				dp[x][y] += sum;
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<=3000;x++){
		ans += dp[n-1][x];
		ans %= mod;
	}
	
	cout << ans << "\n";
    return 0;
}

