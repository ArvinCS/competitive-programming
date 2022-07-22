#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = -1e18;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		ll d;
		cin >> n >> d;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		if(n == 1){
			cout << d-1 << "\n";
			continue;
		}
		
		ll prefix[n], suffix[n];
		prefix[0] = a[0]-1;
		for(int x=1;x<n;x++){
			ll dist = a[x]-a[x-1]-1;
			
			prefix[x] = min(prefix[x-1], dist);
		}
		
		suffix[n-1] = a[n-1]-(n > 1 ? a[n-2] : 0)-1;
		for(int x=n-2;x>=0;x--){
			ll dist = a[x]-(x > 0 ? a[x-1] : 0)-1;
			
			suffix[x] = min(suffix[x+1], dist);
		}
		
		ll mx = max(0ll, 2*(d-a[n-1]-1)+1);
		for(int x=0;x<n;x++){
			ll dist = a[x]-(x > 0 ? a[x-1] : 0)-1;
			mx = max(mx, dist);
		}
		
		ll ans = prefix[n-1];
		for(int y=0;y<n;y++){
			ll new_dist = (y+1 < n ? a[y+1] : d+1) - (y > 0 ? a[y-1] : 0) - 1;
	
			ll new_ans = min((y > 0 ? prefix[y-1] : 1e18), (y+2 < n ? suffix[y+2] : 1e18));
			if(y+1 < n){
				new_ans = min(new_ans, new_dist);
				new_ans = min(new_ans, (max(new_dist, mx)-1)/2);
			} else {
				new_ans = min(new_ans, (max(2*(new_dist-1)+1, mx)-1)/2);
			}
			
			ans = max(ans, new_ans);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

