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
		
		sort(a, a+n);
		
		ll b[n];
		b[0] = a[0];
		for(int x=1;x<n;x++){
			b[x] = a[x] + b[x-1];
		}
		
		auto get = [&](int l, int r) -> ll {
			if(l > r) return 0;
			return b[r] - (l > 0 ? b[l-1] : 0);
		};
		
		ll ans = get(n-n/2, n-1);
		for(int x=0;x<n;x++){
			int mn = min(n/2-1, n-x-1);
			int rem = n/2-1-mn;
			
			ans = max(ans, -a[x]+get(n-1-mn+1, n-1)+get(x-1-rem+1, x-1));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

