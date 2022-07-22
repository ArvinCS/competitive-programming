#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

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
	
	int t;
	cin >> t;
	
	while(t--){
		ll b, q, y;
		cin >> b >> q >> y;
		
		ll c, r, z;
		cin >> c >> r >> z;
		
		if(b > c || r%q != 0 || b+q*(y-1) < c+r*(z-1) || (c-b)%q != 0){
			cout << "0\n";
			continue;
		}
		
		// note D as a new comm difference, A as a new first term.
		// D must a divisor of q
		// the number of terms must less than lcm(q, d)/d
		// A must greater than c - lcm(q, d)/d * r
		// A must less or greater than c
		
		ll ans = 0;
		
		auto solve = [&](ll d) -> void {		
			ll lcm = (q*d)/__gcd(q, d);
			ll cnt = (lcm/d);
			
			if(c-cnt*d < b){
				ans = -1;
				return;
			}
			if(c+r*(z-1)+cnt*d > b+q*(y-1)){
				ans = -1;
				return;
			}
			if(q % d == 0 || ((r/d)/cnt) > 1){
				return;
			}
			
			cnt %= mod;
			ans += cnt * cnt % mod;
			ans %= mod;
		};
		
		for(ll x=1;x*x<=r;x++){
			if(r%x == 0){
				if(ans == -1) break;
				solve(x);
				
				if(ans == -1) break;
				if(r/x != x) solve(r/x);
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

