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
		ll m;
		cin >> n >> m;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		ll prefix[n];
		prefix[0] = a[0];
		for(int x=1;x<n;x++){
			prefix[x] = a[x] + prefix[x-1];
		}
		
		ll ans = 0;
		ll cur = 0;
		for(int x=n-1;x>=0;x--){
			ll pos = cur-1;
			ll left = cur, right = 1e9;
			while(left <= right){
				ll mid = (left+right) >> 1;
				
				if(prefix[x]+mid*(x+1) <= m){
					pos = mid;
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			if(pos < cur) continue;
			
			ans += (x+1)*1ll*(pos-cur+1);
			cur = pos+1;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

