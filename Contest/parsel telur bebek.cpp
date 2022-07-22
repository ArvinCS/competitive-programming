#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

ll parsel(ll data[], ll n, ll x){
	ll total = 0;
	for(ll a=n;a>0;a--){
		total += floor(x/data[a-1]);
		//cout << x << " divide by " << data[a-1] << "\n";
	}
	return total;
}

ll findLow(ll n, ll data[], ll m, ll left, ll right){
	ll low = left, high = right;
	while(low <= high){
		ll mid = (low+high)/2;
		if(parsel(data, n, mid) >= m){
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

ll findHigh(ll n, ll data[], ll m, ll left, ll right){
	ll low = left, high = right;
	while(low <= high){
		ll mid = (low+high)/2;
		if(parsel(data, n, mid) > m){
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

ll findRange(ll n, ll m, ll data[], ll left, ll right){
	if(left == right) return parsel(data, n, left) == m;
	return findHigh(n, data, m, left, right) - findLow(n, data, m, left, right);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n,m;
	cin >> n >> m;
	
	ll data[n];
	for(ll x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	ll lowest = data[0];
	ll size = lowest*m - (lowest-1);
	
	cout << findRange(n,m,data,data[0], data[0]+size) << "\n";
    return 0;
}
