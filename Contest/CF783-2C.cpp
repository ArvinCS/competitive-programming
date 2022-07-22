#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll prefix[n];
	prefix[0] = a[0];
	for(int x=1;x<n;x++){
		prefix[x] = a[x] + prefix[x-1];
	}
	
	ll b[n];
	fill(b, b+n, 0);
	
	ll ans = 0;
	for(int x=1;x<n;x++){
		ll dif = b[x-1]+1;
			
		ll cnt = (dif+a[x]-1)/a[x];
		ans += cnt;
		b[x] += cnt*a[x];
	}
	
	for(int x=0;x<n;x++){
		fill(b, b+n, 0);
		
		ll val = 1;
		b[x] = -a[x];
		for(int y=x-1;y>=0;y--){
			ll dif = abs(b[y+1])+1;
			
			ll cnt = (dif+a[y]-1)/a[y];
			val += cnt;
			b[y] -= cnt*a[y];
		}
		for(int y=x+2;y<n;y++){
			ll dif = abs(b[y-1])+1;
			
			ll cnt = (dif+a[y]-1)/a[y];
			val += cnt;
			b[y] += cnt*a[y];
		}
		
		ans = min(ans, val);
	}
	
	cout << ans << "\n";
    return 0;
}

