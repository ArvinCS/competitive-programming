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
	
	map<ll, ll> mp;
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		mp[data[x]]++;
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		if(mp[data[x]-k] > 0){
			ans++;
		}
	}
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

