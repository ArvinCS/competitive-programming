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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("weak_typing_chapter_3_input.txt","r",stdin);
//	freopen("weak_typing_chapter_3_output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		int k;
		cin >> k;
		
		string s;
		cin >> s;
		
		ll n = 0;
		for(int x=0;x<k;x++){
			if(s[x] != '.') n++;
			else n *= 2;
			
			n %= mod;
		}
		
		vector<pair<char, ll>> v;
		ll ans = 0, sum = 0, cnt = 0, m = 0;
		for(int x=0;x<k;x++){
			if(s[x] != '.'){
				m++;
				m %= mod;
				
				if(s[x] == 'F'){
					continue;
				}
				
				v.push_back({s[x], m});
				
				if(v.size() > 1 && v[v.size()-2].first != v[v.size()-1].first){
					ans += v[v.size()-2].second*1ll*((n-v[v.size()-1].second+1+mod)%mod) % mod;
					ans %= mod;
					
					sum += ((n-v[v.size()-1].second+1+mod) % mod - v[v.size()-2].second + mod) % mod;
					sum %= mod;
					
					cnt++;
					cnt %= mod;
				}
			} else if(s[x] == '.'){
				ans *= 2;
				ans %= mod;
				
				ans += ((sum*m % mod) - (m * m % mod * cnt % mod) + mod) % mod;
				ans %= mod;
				
				sum += (sum - 2*m*cnt % mod + mod) % mod;
				sum %= mod;
				
				cnt *= 2;
				cnt %= mod;
				
				if(v.size() > 1 && v[0].first != v.back().first){
					ans += v.back().second * 1ll * ((n-(m+v[0].second) % mod + 1 + mod)%mod) % mod;
					ans %= mod;
					
					sum += ((n-(m+v[0].second) % mod + 1 + mod) % mod - v.back().second + mod) % mod;
					sum %= mod;
							
					cnt++;
					cnt %= mod;
				}
				
				if(v.size() > 0){
					pair<char, ll> p = v.back();
					
					v.push_back({v[0].first, (v[0].second+m) % mod});
					if(v.size() > 2) v.push_back({p.first, (p.second+m) % mod});
				}
				
				m *= 2;
				m %= mod;
			}
		}
		
		cout << "Case #" << i << ": " << ans % mod << "\n";
	}

    return 0;
}

