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
		ll a, b;
		cin >> n >> a >> b;
		
		ll p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
		}
		
		ll prefix[n];
		prefix[0] = p[0];
		for(int x=1;x<n;x++){
			prefix[x] = p[x] + prefix[x-1];
		}
		
		ll ans = prefix[n-1]*b;
		for(int x=0;x<n;x++){
			ans = min(ans, p[x]*(a+b) + ((prefix[n-1]-prefix[x])-(n-x-1)*p[x])*b);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

