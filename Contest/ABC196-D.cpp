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

ll fac[100];
ll h, w;

ll dp(ll n, ll a, ll b){
	if(n == w) return 1;
	if(n > w) return 0;
	cout << "- " << n << "\n";
	ll ans = 0;
	
	for(ll x=0;x*2<=h;x++){
		ll y = h-2*x;
		ll ways = fac[x+y] / (fac[x] * fac[y]);
		
		if(x <= a && y <= b){
			ans += ways * dp(n+1, a-x, b-y);
		}
	}
	
	for(ll x=0;x*2<=h;x++){ // ver 2*1
		for(ll y=0;y<=h-2*x;y++){ // hor 1*2
			ll z = h-2*x-y;
			ll ways = fac[x+y+z] / (fac[x] * fac[y] * fac[z]);
			
			if(2*x+y <= a && 2*z <= b){
				ans += ways * dp(n+2, a-x-y, b-z);
			}
		}
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
	for(ll x=2;x<25;x++){
		fac[x] = x*fac[x-1];
	}
	
	ll a, b;
	cin >> h >> w >> a >> b;
//	
//	for(int x=0;x*2<=h;x++){
//		int y = h-2*x;
//		table[1] += fac[x+y] / (fac[x] * fac[y]);
//	}
//	
//	ll tmp[h+1];
//	fill(tmp, tmp+h+1, 0);
//	
//	table[0] = 1;
//	for(int x=0;x<=h;x++){
//		tmp[x+2] += table[x];
//		tmp[x+1] += table[x] * 2;
//	}
//	table[2] = tmp[h];
//	
//	cout << table[1] << " " << table[2] << "\n";
	cout << dp(0, a, b) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

