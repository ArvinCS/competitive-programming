#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 1e7 + 5;

int prime[maxA], cnt[maxA];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for(int x=0;x<maxA;x++){
		prime[x] = x;
		cnt[x] = 0;
	}
	for(int x=2;x*x<maxA;x++){
		if(prime[x] == x){
			for(int y=2*x;y<maxA;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	ll ans = 0;
	for(int x=n-1;x>=0;x--){
		if(a[x] > 1){
			ll val = a[x];
			ll div = prime[val];
			
			while(val % div == 0) val /= div;
			
			if(a[x] % 2 == 0 && val != 1){
				for(int y=1;y*a[x]<=a[n-1];y++){
					if(__gcd(a[x], y*1ll) != y) continue;
					
					ans += cnt[y*a[x]];
				}
			} else if(val == 1){
				ll cur = div;
				while(cur <= a[n-1]){
					ans += cnt[cur];
					cur *= div;
				}
			}
		} else {
			ans += cnt[a[x]];
		}
		
		cnt[a[x]]++;
	}
	
	cout << ans << "\n";
	return 0;
}
