#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	vector<ll> v;
	for(ll x=1;x*x<=n;x++){
		if(n%x == 0){
			v.push_back(x);
			if(n/x != x) v.push_back(n/x);
		}
	}
	
	sort(v.begin(), v.end());
	
	ll ans = 0;
	ll pos = 1;
	while(pos <= n){
		ll left = pos, right = n, mx = pos;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			if(n/mid == n/pos){
				left = mid+1;
				mx = max(mx, mid);
			} else {
				right = mid-1;
			}
		}
		
		ans += (mx-pos+1)*(n/pos);
		pos = mx+1;
	}
	
	cout << ans << "\n";
    return 0;
}

