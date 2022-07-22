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
		int n, k;
		cin >> n >> k;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		int cnt[31];
		fill(cnt, cnt+31, 0);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<31;y++){
				ll bit = (1ll << y);
				
				if(a[x]&bit){
					cnt[y]++;
				}
			}
		}
		
		ll ans = 0;
		for(int i=30;i>=0;i--){
			if(n-cnt[i] <= k){
				k -= n-cnt[i];
				ans |= (1ll << i);
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

