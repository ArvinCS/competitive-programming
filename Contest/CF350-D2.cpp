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

	ll n, k;
	cin >> n >> k;
	
	ll need[n];
	for(int x=0;x<n;x++){
		cin >> need[x];
	}
	
	ll have[n];
	for(int x=0;x<n;x++){
		cin >> have[x];
	}
	
	ll left = 1, right = 2e9, ans = 0;
	while(left <= right){
		ll mid = (left+right) >> 1ll;
		
		ll cur = k;
		for(ll x=0;x<n;x++){
			cur -= max(0ll, need[x]*mid - have[x]);
			if(cur < 0) break;
		}
		
		if(cur >= 0){
			ans = max(ans, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

