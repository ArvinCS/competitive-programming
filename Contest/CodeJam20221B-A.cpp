#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		int d[n];
		for(int x=0;x<n;x++){
			cin >> d[x];
		}
		
		ll ans = 0;
		int mx = 0;
		int l = 0, r = n-1;
		while(l <= r){
			if(d[l] <= d[r]){
				ans += (mx <= d[l]);
				mx = max(mx, d[l]);
				l++;
			} else {
				ans += (mx <= d[r]);
				mx = max(mx, d[r]);
				r--;
			}
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

