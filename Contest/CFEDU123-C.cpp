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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}

		ll suffix[n+1][n];
		suffix[0][n-1] = a[n-1];
		for(int x=n-2;x>=0;x--){
			suffix[0][x] = max(a[x], suffix[0][x+1]+a[x]);	
		}
		
		suffix[1][n-1] = suffix[0][n-1]+m;
		for(int x=n-2;x>=0;x--){
			suffix[1][x] = max(suffix[0][x]+m, suffix[1][x+1]+a[x]);	
		}
		
		for(int x=2;x<=n;x++){
			for(int y=n-1;y>=0;y--){
				suffix[x][y] = suffix[x-1][y];
				
				if(y+1 < n){
					suffix[x][y] = max(suffix[x][y], max(suffix[x-1][y+1]+a[y]+m, suffix[x][y+1]+a[y]));
				}
			}
		}
		
		for(int x=0;x<=n;x++){
			if(x > 0) cout << " ";
			
			ll ans = 0;
			for(int y=0;y<n;y++){
				ans = max(ans, suffix[x][y]);
			}
			cout << ans;
		}
		cout << "\n";
	}
	
    return 0;
}

