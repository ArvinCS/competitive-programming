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
		
		pair<ll, ll> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
		}
		
		ll ans = p[0].first;
		ll cur = 0, sum = 0;
		for(int x=0;x<n;x++){
			if(p[x].first >= 0){
				sum += cur*p[x].second;
				sum += p[x].first*(p[x].second*(p[x].second+1)/2);
			} else {
				ll need = cur/-p[x].first;
				
				if(cur <= 0 || need > p[x].second){
					sum += cur*p[x].second;
					sum += p[x].first*(p[x].second*(p[x].second+1)/2);
				} else {
					sum += cur*need;
					sum += p[x].first*(need*(need+1)/2);
					
					ans = max(ans, sum);
					
					sum -= cur*need;
					sum -= p[x].first*(need*(need+1)/2);
					
					sum += cur*p[x].second;
					sum += p[x].first*(p[x].second*(p[x].second+1)/2);
				}
			}
			
			cur += p[x].first*p[x].second;
			ans = max(ans, sum);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

