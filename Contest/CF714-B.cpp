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

const int maxN = 2e5 + 5;

ll fac[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % mod;
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		map<ll, ll> mp;
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			mp[data[x]]++;
		}
		
		sort(data, data+n);
		
		bool valid = true;
		for(int x=1;x<n;x++){
			if((data[0]&data[x]) != data[0]){
				valid = false;
				break;
			}
		}
		
		if(!valid){
			cout << "0\n";
			continue;
		}
		
		ll ans = 0;
		if(mp[data[0]] > 1){
			ans += ((mp[data[0]]*(mp[data[0]]-1)) % mod * fac[n-2]) % mod;
			ans %= mod;
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

