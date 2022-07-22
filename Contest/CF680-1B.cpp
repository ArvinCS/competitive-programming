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

const int maxN = 3e5 + 10;

ll fac[maxN];

ll modpow(ll a, ll b){
	ll ans = 1;
	a %= smod;
	
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
	b %= smod;
	
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
	
	fac[0] = fac[1] = 1;
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % smod;
	}
	
	int n;
	cin >> n;
	
	int data[2*n];
	for(int x=0;x<2*n;x++){
		cin >> data[x];
	}

	ll a[2*n], b[2*n];
	for(int x=0;x<2*n;x++){
		a[x] = b[x] = data[x];
	}
	
	sort(a, a+2*n);
	sort(b, b+2*n, greater<ll>());
	
	ll cnt = 0;
	for(int x=0;x<n;x++){
		cnt += abs(b[x] - a[x]);
		cnt %= smod;
	}
	
	cout << mulmod(cnt, mulmod(mulmod(fac[2*n], modpow(fac[n], smod-2)), modpow(fac[n], smod-2))) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

