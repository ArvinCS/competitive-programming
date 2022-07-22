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

const int maxN = 5 * 1e4 + 5;

bool prime[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fill(prime, prime+maxN, true);
	
	set<ll> s;
	for(ll x=2;x<=50000;x++){
		if(!prime[x]) continue;
		s.insert(x);
		for(ll y=x*x;y<=50000;y+=x){
			prime[y] = false;
		}
	}
	
	us t;
	cin >> t;
	
	while(t--){
		ll d;
		cin >> d;
		
		ll ans[4];
		ans[0] = 1;
		ans[1] = *s.lower_bound(1+d);
		ans[2] = *s.lower_bound(ans[1]+d);
		ans[3] = (ans[1]*ans[2])/(__gcd(ans[1], ans[2]));
		
		cout << ans[3] << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

