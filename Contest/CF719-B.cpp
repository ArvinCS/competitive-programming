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

int len(ll x){
	int ans = 0;
	while(x > 0){
		ans++;
		x /= 10;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	vector<ll> v;
	for(int x=1;x<=9;x++){
		ll cur = x;
		while(len(cur) <= 9){
			v.push_back(cur);
			cur *= 10;
			cur += x;
		}
	}
	sort(v.begin(), v.end());
	
	us t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		int ans = (upper_bound(v.begin(), v.end(), n) - v.begin());
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

