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
	
	ll arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	ll a = arr[0], b = arr[1], c = arr[2];
	
	// 3 cases, a, b, c changed
	ll ans = inf_ll;
	if((2*b-c) >= a){
		ans = min(ans, (2*b-c) - a);
	}
	if((a+c+1)/2 >= b){
		if((a+c) % 2 != 0){
			ans = min(ans, (a+c+1)/2 - b + 1);
		} else {
			ans = min(ans, (a+c)/2 - b);
		}
	}
	if((2*b-a) >= c){
		ans = min(ans, (2*b-a) - c);
	}
	
	cout << ans << "\n";
    return 0;
}

