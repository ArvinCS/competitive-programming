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
		
		ll h[n];
		for(int x=0;x<n;x++){
			cin >> h[x];
		}
		
		sort(h, h+n);
		
		ll ans = 1e18;
		for(ll mx=h[n-1];mx<=h[n-1]+1;mx++){
			ll odd = 0, even = 0;
			for(int x=0;x<n;x++){
				ll need = (mx-h[x])/2;
				
				even += need;
				if((mx-h[x])&1){
					odd++;
				}
			}
			
			ll need = (even+1-odd)/3;
			
			if(need > 0){
				odd += 2*need;
				even -= need;
			}
			
			ans = min(ans, max(1+(odd-1)*2, even*2));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

