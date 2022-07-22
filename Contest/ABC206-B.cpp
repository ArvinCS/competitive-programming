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
	
	ll n;
	cin >> n;
	
	ll left = 1, right = 1e5 + 5, ans = 0;
	while(left <= right){
		ll mid = (left+right) >> 1ll;
		
		ll cnt = mid*(mid+1)/2;
		if(cnt >= n){
			ans = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}
