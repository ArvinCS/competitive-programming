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
	while(y > 0){
		if(y&1) ans = (ans * x);
		
		y >>= 1;
		x = (x * x);
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
		int n;
		cin >> n;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll zero = 0, one = 0;
		for(int x=0;x<n;x++){
			if(a[x] == 0) zero++;
			else if(a[x] == 1) one++;
		}
		
		ll ans = one*powmod(2, zero);
		cout << ans << "\n";
	}

    return 0;
}

