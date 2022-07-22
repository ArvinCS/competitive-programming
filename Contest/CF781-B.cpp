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
		
		sort(a, a+n);
		
		int mx = 0;
		ll last = 1e18;
		int cnt = 0;
		for(int x=0;x<n;x++){
			if(last != a[x]){
				last = a[x];
				cnt = 0;
			}
			
			cnt++;
			if(cnt > mx) mx = cnt;
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			if(mx >= n){
				break;
			}
			
			ans += min(mx, n-mx)+1;
			mx *= 2;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

