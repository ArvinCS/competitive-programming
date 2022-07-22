#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll l, w;
	cin >> n >> l >> w;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll ans = 0;
	ll mx = 0;
	for(int x=0;x<n;x++){
		if(mx < a[x]){
			ll need = (a[x]-mx+w-1)/w;
			
			ans += need;
			mx += need*w;
		}
		mx = max(mx, a[x]+w);
	}
	
	if(mx < l){
		ll need = (l-mx+w-1)/w;
		
		ans += need;
		mx += need*w;
	}
	
	cout << ans << "\n";
    return 0;
}

