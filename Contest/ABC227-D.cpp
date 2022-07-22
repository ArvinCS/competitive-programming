#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	ll a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		b[x] = 0;
	}
	
	ll left = 0, right = 1e18/k, ans = 0;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		ll sum = 0;
		for(int x=0;x<n;x++){
			sum += min(a[x], mid);
		}
		
		if(mid*k <= sum){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

