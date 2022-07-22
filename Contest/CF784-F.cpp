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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		map<ll, int> mp;
		
		ll suffix[n];
		suffix[n-1] = a[n-1];
		mp[suffix[n-1]] = 1;
		for(int x=n-2;x>=0;x--){
			suffix[x] = a[x] + suffix[x+1];
			mp[suffix[x]] = n-x;
		}
		
		ll sum = 0;
		int ans = 0;
		for(int x=0;x<n;x++){
			mp[suffix[x]] -= n-x;
			sum += a[x];
			
			if(mp[sum] > 0) ans = max(ans, x+1+mp[sum]);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

