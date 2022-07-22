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
		
		sort(a, a+n);
		
		map<ll, int> mp;
		for(int x=0;x<n;x++){
			mp[a[x]]++;
		}
		
		int ans = 0;
		for(int x=0;x<n;x++){
			if(mp[a[x]] > 0){
				mp[a[x]]--;
				
				if(mp[a[x]*m] > 0){
					mp[a[x]*m]--;
				} else {
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

