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

ll ask(ll l, ll r){
	cout << "? " << l << " " << r << endl;
	
	ll res;
	cin >> res;
	
	assert(res >= 0);
	return res;
}

pair<ll, bool> isValid(ll x){
	ll left = 1, right = 1e9 - 1, ans = -2;
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		if(mid*(mid+1)/2 > x){
			right = mid-1;
		} else {
			ans = max(ans, mid);
			left = mid+1;
		}
	}
	
	return {ans, (ans*(ans+1)/2 == x)};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		ll sum = ask(1, n);
		
		ll i = -1, j = -1, k = n;
		ll left = 3, right = n;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll res = ask(1, mid);
			
			if(res == sum){
				k = min(k, mid);
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		ll prv = ask(1, k-1);
		j = k-(sum-prv);
		
		ll prv2 = ask(1, j-1);
		ll prv3 = ask(1, j-2);
		i = j-(prv2-prv3)-1;
		
		cout << "! " << i << " " << j << " " << k << endl;
	}

    return 0;
}

