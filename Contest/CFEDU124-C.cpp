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
		int n;
		cin >> n;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll b[n];
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		ll ans = 1e18;
		
		ll botleft = 1e18, botright = 1e18;
		ll topleft = 1e18, topright = 1e18;
		for(int x=0;x<n;x++){
			botleft = min(botleft, abs(b[0]-a[x]));
			botright = min(botright, abs(b[n-1]-a[x]));
			topleft = min(topleft, abs(a[0]-b[x]));
			topright = min(topright, abs(a[n-1]-b[x]));
		}
		
		ans = min(ans, min(topleft+botleft, abs(a[0]-b[0]))+min(topright+botright, abs(a[n-1]-b[n-1])));
		ans = min(ans, min(topleft+botright, abs(a[0]-b[n-1]))+min(topright+botleft, abs(a[n-1]-b[0])));
		
		cout << ans << "\n";
	}
	
    return 0;
}

