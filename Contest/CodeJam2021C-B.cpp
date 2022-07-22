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

ll len(ll x){
	ll ans = 0;
	while(x > 0){
		ans++;
		x /= 10;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		cout << "Case #" << i << ": ";
		ll n;
		cin >> n;
		
		vector<ll> v;
		ll cur = n;
		while(cur > 0){
			v.push_back(cur%10);
			cur /= 10;
		}
		
		ll ans = inf_ll;
		ll length = len(n);
		if(length == 1){
			ans = 12;
		} else {
			ll tmp = 0, tmp2 = 1;
			for(ll x=1;x<=length/2;x++){
				tmp2 *= 10ll;
				tmp = (tmp * 10ll + v.back());
				v.pop_back();
				
				for(ll y=tmp2/10;y<=tmp2;y++){
					ll num = y;
					ll z = y+1;
					while(len(num) < length){
						num = (num*pow(10ll, len(z)) + z);
						z++;
					}
					if(num > n){
						ans = min(ans, num);
					}
				}
			}
		}
		
		cout << ans << " " << n << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

