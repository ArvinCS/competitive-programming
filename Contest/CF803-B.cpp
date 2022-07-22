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
		
		if(k == 1){
			cout << (n-1)/2 << "\n";
			continue;
		}
		
		int ans = 0;
		for(int x=1;x<n-1;x++){
			if(a[x-1]+a[x+1] < a[x]){
				ans++;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

