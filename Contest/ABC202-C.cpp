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
	
	int n;
	cin >> n;
	
	int a[n], b[n], c[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	for(int x=0;x<n;x++){
		cin >> c[x];
		c[x] = b[c[x]-1];
	}
	
	map<int, ll> mp;
	for(int x=0;x<n;x++){
		mp[c[x]]++;
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ans += mp[a[x]];
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

