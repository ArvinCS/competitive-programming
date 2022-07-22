#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	ll mn = 1e18;
	for(ll a=0;a*a*a<=mn;a++){
		ll left = 0, right = min(1000000ll, mn-a*a*a);
		
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll val = a*a*a+a*a*mid+a*mid*mid+mid*mid*mid;
			if(val >= n){
				right = mid-1;
				mn = min(mn, val);
			} else {
				left = mid+1;
			}
		}
	}
	
	cout << mn << "\n";
    return 0;
}

