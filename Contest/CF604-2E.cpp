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
	if(x == 0) return 0;
	
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % smod;
		
		y >>= 1;
		x = (x * x) % smod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ans = (ans + 1) * powmod(p[x] * powmod(100, smod-2) % smod, smod-2) % smod;
	}
	cout << ans << "\n";
    return 0;
}

