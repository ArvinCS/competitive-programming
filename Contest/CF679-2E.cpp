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

ll a, b, c, d;

ll calc(ll pos){
	ll done = pos/d + 1;
	ll res = done * (2*pos + (done-1)*(-d)) / 2;
	
	return done*a-res*b;
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
		cin >> a >> b >> c >> d;
		
		if(b >= a){
			cout << a << "\n";
			continue;
		}
		if(c*b < a){
			cout << "-1\n";
			continue;
		}
		
		ll ans = 0;
		int left = 0, right = c/d;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(calc(mid*d) < calc((mid+1)*d)){
				left = mid+1;
			} else {
				ans = max(ans, calc(mid*d));
				right = mid-1;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

