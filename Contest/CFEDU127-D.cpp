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
		
		ll mn = 1e9, mx = -1;
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			if(mn > a[x]) mn = a[x];
			if(mx < a[x]) mx = a[x];
		}
		
		ll ans = 0;
		for(int x=0;x+1<n;x++){
			ans += abs(a[x]-a[x+1]);
		}
		
		ll ans2 = 1e18;
		ll ans3 = 1e18, ans4 = 1e18;
		
		// place at the beginning
		ans2 = min(ans2, m-1+abs(a[0]-m));
		ans2 = min(ans2, m-1+abs(a[0]-1));
		ans3 = min(ans3, max(0ll, a[0]-1));
		ans4 = min(ans4, max(0ll, m-a[0]));
		
		for(int x=0;x+1<n;x++){
			// place between x and x+1
			ans2 = min(ans2, 2*max(0ll, min(a[x], a[x+1])-1)+2*max(0ll, m-max(a[x], a[x+1])));
			ans2 = min(ans2, 2*max(0ll, max(a[x], a[x+1])-1)+2*max(0ll, m-min(a[x], a[x+1])));
			
			ans2 = min(ans2, ans3+2*max(0ll, m-max(a[x], a[x+1])));
			ans2 = min(ans2, ans4+2*max(0ll, min(a[x], a[x+1])-1));
			
			ans3 = min(ans3, 2*max(0ll, min(a[x], a[x+1])-1));
			ans4 = min(ans4, 2*max(0ll, m-max(a[x], a[x+1])));
		}
		
		// place at the end
		ans2 = min(ans2, abs(a[n-1]-1)+(m-1));
		ans2 = min(ans2, abs(m-a[n-1])+(m-1));
		if(mx < m) ans2 = min(ans2, ans3+abs(a[n-1]-m));
		if(1 < mn) ans2 = min(ans2, ans4+abs(a[n-1]-1));
		
		cout << ans+ans2 << "\n";
	}
	
    return 0;
}

