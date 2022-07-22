#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define smod 998244353

const int maxN = 2e5 + 5;

ll fac[maxN], iv[maxN], pwK[maxN], pwK1[maxN], pwK2[maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	x %= smod;
	
	while(y>0){
		if(y&1) ans = (ans*x) % smod;
		
		y >>= 1;
		x = (x*x) % smod;
	}
	return ans;
}

ll combin(ll x, ll y){
	return (fac[x] * iv[x-y] % smod * iv[y] % smod);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fac[0] = fac[1] = 1;
	iv[0] = iv[1] = powmod(1, smod-2);
	for(ll x=2;x<maxN;x++){
		fac[x] = (x * fac[x-1]) % smod;
		iv[x] = powmod(fac[x], smod-2);
	}
	
	ll n, k;
	cin >> n >> k;
	
	ll h[n];
	for(int x=0;x<n;x++){
		cin >> h[x];
	}
	
	// 3 cases:
	// 1 before move better
	// 2 after move better
	// 3 neither better
	
	ll cnt = 0;
	for(int x=0;x<n;x++){
		if(h[x] != h[(x+1)%n]){
			cnt++;
		}
	}
	
	pwK[0] = pwK1[0] = pwK2[0] = 1;
	for(ll x=1;x<maxN;x++){
		pwK[x] = (k * pwK[x-1]) % smod;
		pwK1[x] = ((k-1) * pwK1[x-1]) % smod;
		pwK2[x] = ((k-2) * pwK2[x-1]) % smod;
	}
	
	ll ans = 0;
	for(ll x=0;x*2<=cnt;x++){ // how many case 1 and 2 appear equal
		ans += (combin(cnt, x) * combin(cnt-x, x) % smod * pwK2[cnt-2*x] % smod * pwK[n-cnt] % smod);
		ans %= smod;
	}
	
	cout << ((pwK[n] - ans + smod) * powmod(2, smod-2) % smod) << "\n"; // divide by 2 because there's case where case 2 < case 1
    return 0;
}

