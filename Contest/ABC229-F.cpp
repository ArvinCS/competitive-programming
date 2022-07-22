#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	cin >> n;
	
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	ll cnt[2];
	cnt[0] = cnt[1] = 0;
	for(int x=0;x<n;x++){
		cnt[x&1] += a[x];
	}
	
	ll ans = 1e18;
	if(n&1){
		for(int x=0;x<n;x++){
			cnt[x&1] -= a[x];
			cnt[(x&1)^1] += a[x];
			
			ans = min(ans, min(cnt[0], cnt[1])+b[x]);
		}
	} else {
		ans = min(cnt[0], cnt[1]);
	}
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += b[x];
	}
	
	ans = min(ans, sum);
	cout << ans << "\n";
    return 0;
}

