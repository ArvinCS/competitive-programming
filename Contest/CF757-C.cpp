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

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
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
		
		int l[m], r[m];
		ll k[m];
		for(int x=0;x<m;x++){
			cin >> l[x] >> r[x] >> k[x];
			l[x]--; r[x]--;
		}
		
		ll sum = 0;
		for(int x=0;x<m;x++){
			sum |= k[x];
		}
		
		ll ans = sum*powmod(2, n-1) % mod;
		cout << ans << "\n";
	}
	
    return 0;
}

