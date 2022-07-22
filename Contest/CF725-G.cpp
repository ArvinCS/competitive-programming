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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		ll n, m, a, b;
		cin >> n >> m >> a >> b;
		
		if(n > m) swap(n, m); // n <= m
		if(a > b) swap(a, b); // a <= b
		
		if(a == b){
			cout << n/a << "\n";
		} else {
			ll left = 0, right = inf_int, ans = 0;
			while(left <= right){
				ll mid = (left+right) >> 1;
				
				ll x = n-mid*a;
				ll y = m-mid*a;
				
				if(x < 0 || y < 0){
					right = mid-1;
					continue;
				}
				
				if(x/(b-a) + y/(b-a) >= mid){
					left = mid+1;
					ans = max(ans, mid);
				} else {
					right = mid-1;
				}
			}
			cout << ans << "\n";
		}
	}

    return 0;
}



