#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n; 
	ll k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n, greater<ll>());
	
	ll ans = 0, cur = 0, cnt = 1;
	for(int x=0;x+1<n;x++){
		ll diff = a[x] - max(a[x+1], 0ll);
		
		if(diff*cnt > k){			
			ll tmp = k/cnt;
			ll val = (a[x]*(a[x]+1)/2 - (a[x]-tmp)*(a[x]-tmp+1)/2) * cnt + (a[x]-tmp)*(k%cnt);
			
			ans += val; 
			k = 0;
			
			break;	
		}
		
		ll val = (a[x]*(a[x]+1)/2 - a[x+1]*(a[x+1]+1)/2)*cnt;
		ans += val;
		k -= diff*cnt;
		
		cnt++;
	}
	
	if(k > 0){
		if(a[n-1]*cnt > k){
			ll tmp = k/cnt;
			ll mn = max(a[n-1]-tmp, 0ll);
			ll val = (a[n-1]*(a[n-1]+1)/2 - mn*(mn+1)/2) * cnt + mn*(k%cnt);
			
			ans += val; 
			k = 0;
		} else {
			ans += (a[n-1]*(a[n-1]+1)/2)*cnt;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

