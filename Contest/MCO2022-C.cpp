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
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	pair<ll, ll> p[k];
	map<pair<ll, ll>, char> mp;
	set<pair<ll, ll>> st;
	for(int x=0;x<k;x++){
		cin >> p[x].first >> p[x].second;
		cin >> mp[p[x]];
	}
	
	ll ways = powmod(2, n*1ll*m-9-k);
	ll ans = (n-2)*1ll*(m-2) % mod * ways % mod;
	
	
	for(int x=0;x<k;x++){
		for(int x1=-2;x1<=0;x1++){
			for(int y1=-2;y1<=0;y1++){
				if(st.count({p[x].first+x1, p[x].second+y1})) continue;
				if(p[x].first+x1 < 0 || p[x].second+y1 < 0) continue;
				if(p[x].first+x1+2 >= n || p[x].second+y1+2 >= m) continue;
				
				st.insert({p[x].first+x1, p[x].second+y1});
				
				bool valid = true;
				int cnt = 0;
				for(int x2=0;x2<3;x2++){
					for(int y2=0;y2<3;y2++){
						auto it = mp.find({p[x].first+x1+x2, p[x].second+y1+y2});
						if(x2 == 1 && y2 == 1){
							if(it != mp.end() && (*it).second == 'B'){
								valid = false;
							}
						} else {
							if(it != mp.end() && (*it).second == 'W'){
								valid = false;
							}
						}	
						if(it != mp.end()) cnt++;
					}
				}
				
				if(!valid){
					ans -= ways;
					if(ans < 0) ans += mod;
				} else {
					ans -= ways;
					if(ans < 0) ans += mod;
					
					ans += powmod(2, n*m-9-(k-cnt));
					if(ans >= mod) ans -= mod;
				}
			}
		}
	}
	
	cout << ans % mod << "\n";
    return 0;
}

