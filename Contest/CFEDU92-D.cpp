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
		ll k;
		cin >> n >> k;
		
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		
		if(a > c){
			swap(a, c);
			swap(b, d);
		}
		
		ll ans = 0;
		if(b >= c){
			k -= min(n*min(b-c, d-c), k);
			
			for(int x=0;x<n;x++){
				ll cnt = min(k, c-a+abs(b-d));
				
				ans += cnt;
				k -= cnt;
			}
			
			ans += 2*k;
			k -= k;
		} else {
			if((c-b) % 2 == 0){
				ll mn = c-b;
				ll full = max(d, b)-a;
				
				for(int x=0;x<n;x++){
					if(k <= 0) break;
					ans += mn;
					
					ll cnt = min(k, full);
					k -= cnt;
					ans += cnt;
					
					if(x+1 == n){
						ans += k*2;
						k -= k;
					} else if(min(k, full)*2 <= mn+min(k, full)){
						ans += min(k, full)*2;
						k -= min(k, full);
					}
				}
			} else {
				ll mn = c-b + 1;
				ll full = max(d, b)-a-1;
				
				for(int x=0;x<n;x++){
					if(k <= 0) break;
					ans += mn;
					k--;
					
					ll cnt = min(k, full);
					k -= cnt;
					ans += cnt;
					
					if(x+1 == n){
						ans += k*2;
						k -= k;
					} else if(min(k, full+1)*2 <= mn+min(k-1, full)){
						ans += min(k, full)*2;
						k -= min(k, full);
					}
				}
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

