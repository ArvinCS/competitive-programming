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

ll powmod(ll a, ll b){
	ll ans = 1;
	
	while(b > 0){
		if(b&1) ans = (ans * a) % smod;
		
		b >>= 1;
		a = (a * a) % smod;
	}	
	return ans;
}

ll mulmod(ll a, ll b){
	ll ans = 0;
	a %= smod;
	
	while(b > 0){
		if(b&1) ans = (ans + a) % smod;
		
		b >>= 1;
		a = (a*2) % smod; 
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
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);

	ll ans = mulmod(data[0], data[0]), sum = 0;
	for(int x=1;x<n;x++){
		sum = mulmod(sum, 2);
		sum += data[x-1];
		
		ans += mulmod(data[x], sum);
		ans += mulmod(data[x], data[x]);
		ans %= smod;
	}
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

