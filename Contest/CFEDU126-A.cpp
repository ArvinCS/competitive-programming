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
		
		ll a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		ll ans = 0;
		for(int x=0;x+1<n;x++){
			ans += min(abs(a[x]-a[x+1])+abs(b[x]-b[x+1]), abs(b[x]-a[x+1])+abs(a[x]-b[x+1]));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

