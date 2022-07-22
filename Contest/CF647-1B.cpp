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

ll modpow(ll a, ll b){
	ll ans = 1;
	a %= mod;
	
	while(b > 0){
		if(b&1) ans = (ans * a) % mod;
		
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
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
		int n, m;
		cin >> n >> m;
		
		vector<ll> data;
		for(int x=0;x<n;x++){
			ll tmp;
			cin >> tmp;
			
			data.push_back(tmp);
		}
		
		sort(data.begin(), data.end());
		
		ll ans = modpow(m, data);
		if(n > 1 && data[0] == data[1]){
			
		}
		for(int x=1;x<n;x++){
			ans -= modpow(m, data[x]);
			ans %= mod;
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

