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

unordered_map<ll, ll> mp;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, k;
	cin >> n >> k;
	
	ll data[n], cnt[n];	
	for(ll x=0;x<n;x++){
		cin >> data[x];
		cnt[x] = 0;
	}
	
	sort(data, data+n);

	ll val = 0;
	for(ll x=0;x<n;x++){
		int tmp = data[x];
		data[x] = val;
		cnt[data[x]]++;
		if(x+1 < n && tmp != data[x+1]) val++;
	}
	
//	for(int x=0;x<n;x++){
//		if(x > 0) cout << " ";
//		cout << data[x];
//	}
//	cout << "\n";
	
	ll left = 0, right = val;
	ll ans = 0;
	while(true){
		ll cur = ceil(log2(right-left+1))*n;
		if(cur <= k*8) break;
		
		if(cnt[left] > cnt[right]){
			ans += cnt[right--];
		} else {
			ans += cnt[left++];
		}
	}
	
	cout << ans << "\n";
	return 0;
}
 
// Santai
// Pikirin dengan benar-benar
