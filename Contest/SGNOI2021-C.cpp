#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 1e18;
const int maxN = 4e5 + 5;
const int maxSN = 100;

ll dp[2][maxSN], prefix[maxSN], suffix[maxSN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	ll d[n];
	for(int x=0;x<n;x++){
		d[x] = (p[x]-a[x]+k+1)%(k+1);
	}
	
	if(k == 0){
		cout << "0\n";
		return 0;
	}
	
	priority_queue<int> pq;
	
	fill(dp[0], dp[2], 1e18);
	
	int sz = maxSN-1;
	for(int y=0;y<=sz;y++){
		dp[0][y] = d[0]+y*(k+1);
	}
	
	for(int x=1;x<n;x++){
		prefix[0] = dp[0][0]-d[x-1];
		for(int y=1;y<=sz;y++){
			prefix[y] = min(prefix[y-1], dp[0][y]-(d[x-1]+y*(k+1)));
		}
		
		suffix[sz] = dp[0][sz];
		for(int y=sz-1;y>=0;y--){
			suffix[y] = min(suffix[y+1], dp[0][y]);
		}
		
		for(int y=0;y<=sz;y++){
			if(d[x]+y*(k+1) < d[x-1]){
				dp[1][y] = min(dp[1][y], suffix[0]);
			} else {
				int mn = min(sz*1ll, (d[x]+y*(k+1)-d[x-1])/(k+1));
				cout << dp[0][y]+(d[x]+y*(k+1)) << " ";
				if(mn >= 0) dp[1][y] = min(dp[1][y], prefix[mn]+d[x]+y*(k+1));
				if(mn < sz) dp[1][y] = min(dp[1][y], suffix[mn+1]);
			}
		}cout << "\n";
		
		cout << x << ":\n";
		for(int y=0;y<=sz;y++){
			cout << dp[1][y]-(d[x]+y*(k+1)) << "," << dp[1][y] << " ";
			assert(y+1 > sz || dp[1][y] <= dp[1][y+1]);
			dp[0][y] = dp[1][y];
			dp[1][y] = 1e18;
		}cout << "\n";
	}
	
	ll ans = 1e18;
	for(int y=0;y<=sz;y++){
		ans = min(ans, dp[0][y]);
	}
	cout << ans << "\n";
    return 0;
}

