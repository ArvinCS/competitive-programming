#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 3e5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	ll prefix[n];
	prefix[0] = a[0];
	
	for(int x=1;x<n;x++){
		prefix[x] = a[x] + prefix[x-1];
	}
	
	ll ans = 0;
	for(int x=1;x<=maxA;x++){
		ll cnt = 0;
		int prv = 0;
		for(int y=1;y*x<=2*maxA;y++){
			int idx = lower_bound(a, a+n, y*x+1) - a;
			
			cnt += (idx-prv)*1ll*y*x - (prefix[idx-1] - (prv > 0 ? prefix[prv-1] : 0));
			prv = idx;
		}
		
//		cout << x << " -> " << cnt << "\n";
		if(cnt <= k){
			ans = max(ans, x*1ll);
		}
	}
	
	k -= n*1ll*maxA - prefix[n-1];
	
	if(k >= 0){
		ans = max(ans, maxA * 1ll + k/n);
	}
	
	cout << ans << "\n";
    return 0;
}

