#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k, m;
	cin >> n >> k >> m;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll ans = 0;
	
	for(int x=0;x<n;x++){
		ll mn = min(k, a[x]/m);
		
		a[x] -= m*mn;
		k -= mn;
		
		ans += a[x];
	}
	
	sort(a, a+n);
	
	for(int x=n-1;x>=0;x--){
		if(k == 0) break;
		
		ans -= a[x];
		k--;
	}
	
	cout << ans << "\n";
    return 0;
}

