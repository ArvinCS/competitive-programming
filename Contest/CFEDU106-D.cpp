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

const int maxP = 2e7 + 5;

ll prime[maxP];

ll a, b, c;

ll cnt(ll great){
	if(c % great == 0){
		ll tmp = (c/great + b);
		if(tmp % a != 0) return 0;
		
		tmp /= a;
		
		ll factors = 0;
		
		while(tmp > 1){
			ll m = prime[tmp];
			while(tmp % m == 0) tmp /= m;
			factors++;
		}
		
		return (1ll << factors);
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(ll x=0;x<maxP;x++) prime[x] = x;
	for(ll x=2;x*x<maxP;x++){
		if(prime[x] == x){
			for(ll y=x+x;y<maxP;y+=x){
				prime[y] = x;
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> a >> b >> c;
		
		ll ans = 0;
		for(ll great=1;great*great<=c;great++){
			if(c%great == 0){
				ans += cnt(great);
				if(c/great != great) ans += cnt(c/great);
			}
		}

		cout << ans << "\n";
	}

    return 0;
}
