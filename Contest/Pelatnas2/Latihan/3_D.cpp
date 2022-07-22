#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll a[n+m-1];
	ll b[n+m-1];
	
	ll odd = 0, even = 0;
	for(int x=0;x<n+m-1;x++){
		cin >> a[x];
		
		if(x&1){
			even += a[x];
		} else {
			odd += a[x];
		}
	}
	
	for(int x=0;x<n+m-1;x++){
		cin >> b[x];
	}
	
	if(n == 1){
		ll ans = 0;
		for(int x=0;x<n+m-1;x++){
			ans += min(a[x], b[m-1-x]);
		}
		
		cout << ans << "\n";
		return 0;
	}
	
	ll prefix[n+m-1][2];
	for(int x=0;x<n+m-1;x++){
		if(x > 0){
			prefix[x][0] = prefix[x-1][0];
			prefix[x][1] = prefix[x-1][1];
		} else {
			prefix[x][0] = prefix[x][1] = 0;
		}
		
		if(x&1){
			prefix[x][0] += b[x];
		} else {
			prefix[x][1] += b[x];
		}
	}
	
	int sz = n+m-1;
	ll ans = 0;
	
	// case for even
	int mid = sz/2+1;
	ll cur = even, tmp = 0;
	ll mn = 1e18;
	for(int x=0;x<=sz;x+=2){
		if(mid-x > 0){
			int l = 0;
			if(mid-x < m){
				l = m-(mid-x-1);
			} else {
				l = mid-x-(m-1);
			}
			
			int r = 0;
			if(mid-x < n){
				r = mid-x+(m-1);
			} else {
				r = n+m-(mid-x-n)-1;
			}
			
			if(l > r) swap(l, r);
			
			ll cnt = prefix[r-1][r&1] - (l >= 2 ? prefix[l-2][r&1] : 0);
//			cout << mid-x << " -> " << l << " " << r  << " " << cnt << "-" << cnt+tmp << " " << cur << "\n";

			mn = min(mn, cnt+tmp);
			
			tmp += a[mid-x-1];
			cur -= a[mid-x-1];
		}
		
		if(x > 0 && mid+x <= sz){
			int l = 0;
			if(mid+x < m){
				l = m-(mid+x-1);
			} else {
				l = mid+x-(m-1);
			}
			
			int r = 0;
			if(mid+x < n){
				r = mid+x+(m-1);
			} else {
				r = n+m-(mid+x-n)-1;
			}
			
			if(l > r) swap(l, r);
			
			ll cnt = prefix[r-1][r&1] - (l >= 2 ? prefix[l-2][r&1] : 0);
			
			mn = min(mn, cnt+tmp);
			
			tmp += a[mid+x-1];
			cur -= a[mid+x-1];
		}
	}
	
	mn = min(mn, tmp);
	ans += mn;
	
//	cout << ans << " -\n";
	
	// case for odd
	cur = odd;
	mn = 1e18;
	tmp = 0;
//	cout << cur << "\n";
	for(int x=1;x<=sz;x+=2){
		if(mid-x > 0){
			int l = 0;
			if(mid-x < m){
				l = m-(mid-x-1);
			} else {
				l = mid-x-(m-1);
			}
			
			int r = 0;
			if(mid-x < n){
				r = mid-x+(m-1);
			} else {
				r = n+m-(mid-x-n)-1;
			}
			
			if(l > r) swap(l, r);
			
			ll cnt = prefix[r-1][r&1] - (l >= 2 ? prefix[l-2][r&1] : 0);
			
//			cout << mid-x << " -> " << l << " " << r  << " " << cnt << "-" << cnt+tmp << " " << cur << "\n";
			
			mn = min(mn, cnt+tmp);
			
			tmp += a[mid-x-1];
			cur -= a[mid-x-1];
		}
		
		if(x > 0 && mid+x <= sz){
			int l = 0;
			if(mid+x < m){
				l = m-(mid+x-1);
			} else {
				l = mid+x-(m-1);
			}
			
			int r = 0;
			if(mid+x < n){
				r = mid+x+(m-1);
			} else {
				r = n+m-(mid+x-n)-1;
			}
			
			if(l > r) swap(l, r);
			
			ll cnt = prefix[r-1][r&1] - (l >= 2 ? prefix[l-2][r&1] : 0);
			
			mn = min(mn, cnt+tmp);
			
			tmp += a[mid+x-1];
			cur -= a[mid+x-1];
		}
	}
	
	mn = min(mn, tmp);
	ans += mn;
	
	cout << ans << "\n";
    return 0;
}

