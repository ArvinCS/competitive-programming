#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int maxP = 200;
const int div2 = 500000004;

ll pw[maxP];

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
	cin.tie(0); cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<maxP;x++){
		pw[x] = (2 * pw[x-1]) % mod;
	}
	
	ll n, m;
	cin >> n >> m;
	
	if(n <= 1e7){
		ll ans = 0;
		for(ll x=1;x<=n;x++){
			ans += ((x*m)^m) % mod;
			if(ans >= mod) ans -= mod;
		}
		
		cout << ans << "\n";
		return 0;
	}
	
	int lg = log2(m+1);
	if((1ll << lg) == m+1){
		ll ans = n % mod * ((n+1) % mod) % mod * (m % mod) % mod * div2 % mod;
		if(ans >= mod) ans -= mod;
		
		ll rem = n % (m+1);
		ans -= ((m % mod) * ((m+1) % mod) % mod * div2 % mod - ((m-rem) % mod) * ((m-rem+1) % mod) % mod * div2 % mod + mod) % mod;
		if(ans < 0) ans += mod;
		
		ans += ((rem-1) % mod * (rem % mod) % mod * div2 % mod);
		if(ans >= mod) ans -= mod;
		
		cout << ans << "\n";  
		return 0;	
	}
	
	int mn = m, mx = 0;
//	vector<pair<ll, int>> v;
	for(int i=0;i<38;i++){
		if(m&(1ll << i)){
			mn = min(mn, i);
			mx = max(mx, i);
//			for(int j=i;j<37;j++){
//				if(m&(1ll << j)){
//					v.push_back({1ll << (j-i), j});
//				}
//			}
		}
	}
	
//	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
	
//	ll ans = n % mod * ((n-1+mod) % mod) % mod * m % mod;
//	for(int x=0;x<v.size();x++){
//		ll dist = v[x].first;
//		ll bit = (1ll << v[x].second);
//		
//		ll cnt = 0;
//		for(int y=1;y<=n;y++){
//			if(y&dist){
//				cnt++;
//			}
//		}
//		
//		cout << dist << " " << v[x].second << " -> " << cnt << "\n";
//		ans -= bit * cnt % mod;
//		if(ans < 0) ans += mod;
//	}
	
	ll bound = (1ll << (mx-mn+1));

	int prefix[bound+1];
	for(int x=0;x<=n;x++){
		prefix[x] = (x > 0 ? prefix[x-1] : 0);
		prefix[x] += (((x+1)*m)^m) % mod;
		if(prefix[x] >= mod) prefix[x] -= mod;
	}
	
	ll m2 = m%mod;
	int ans = 0;
	ll bound2 = bound%mod;
	
	if(bound <= 1e8){
		for(int x=0;x<bound;x++){
			ll cnt = (n-x+bound-1)/bound;
			cnt %= mod;
			
			ll val = ((x+1)*m)^m;
			val %= mod;
			
			ans += val * cnt % mod;
			if(ans >= mod) ans -= mod;
			
			ans += ((cnt-1+mod) % mod * cnt % mod * bound2 % mod * m2 % mod * div2 % mod);
			if(ans >= mod) ans -= mod;
		}
	} else {
		for(int x=0;x*bound<=n;x++){			
			ll boundL = -1, boundR = bound;
			ll left = 0, right = bound-1;
			while(left <= right){
				ll mid = (left+right) >> 1;
				
				if((n-mid+bound-1)/bound > x){
					boundL = mid;
					left = mid+1;
				} else {
					right = mid-1;
				}
			}
			
			left = 1, right = n;
			while(left <= right){
				ll mid = (left+right) >> 1;
				
				if((n-mid+bound-1)/bound < x){
					boundR = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
//			cout << x << " -> " << boundL+1 << " " << boundR-1 << " " << bound << " " << prefix[boundR-1] - prefix[boundL]<< "\n";
			ans += (boundL+1 <= boundR-1 ? (prefix[boundR-1] - (boundL >= 0 ? prefix[boundL] : 0) + mod) % mod : 0) *1ll * x % mod;
			if(ans >= mod) ans -= mod;
			
			ans += ((x-1+mod) % mod * x % mod * bound2 % mod * m2 % mod * div2 % mod);
			if(ans >= mod) ans -= mod;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
