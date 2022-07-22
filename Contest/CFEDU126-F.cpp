#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll sqr(ll x){
	return x*x;
}

ll calc(ll len, ll k){
	return (len % (k+1)) * sqr(len/(k+1) + 1) + (k+1 - (len % (k+1))) * sqr(len/(k+1));
}

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
	
	ll w;
	cin >> w;
	
	ll b[n];
	for(int x=0;x<n;x++){
		if(x == 0) b[x] = a[x];
		else b[x] = a[x] - a[x-1];
	}
	
	auto solve = [&](ll mid) -> pair<ll, ll> {
		ll cost = 0, need = 0;
		for(int x=0;x<n;x++){
			int len = b[x];
			
			if(mid <= 2 || len == 1){
				cost += len;
				need += len-1;
				continue;
			}
			
			int pos = -1;
			int left2 = 0, right2 = len-1;
			while(left2 <= right2){
				int mid2 = (left2+right2)/2;
				
				ll val = calc(len, mid2);
				ll val2 = calc(len, mid2+1);
				
				if(val-val2 >= mid){
					pos = mid2;
					left2 = mid2+1;
				} else {
					right2 = mid2-1;
				}
			}
			
			cost += calc(len, pos+1);
			need += pos+1;
		}
		
		return {cost, need};
	};
	
	ll pos = 0;
	ll left = 1, right = 1e18 + 43;
	
	if(solve(right).first <= w){
		cout << 0 << "\n";
		return 0;
	}
	
	while(left <= right){
		ll mid = (left+right)/2;
		
		pair<ll, ll> val = solve(mid);
		
		if(val.first <= w){
			pos = mid;
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	pair<ll, ll> val = solve(pos);
	pair<ll, ll> val2 = solve(pos+1);
	
	ll need = (val2.first-val.first) / (val2.second-val.second);
	cout << val.second + (w-val.first)/need << "\n";
    return 0;
}

