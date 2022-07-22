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
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		ll query[m];
		for(int x=0;x<m;x++){
			cin >> query[x];
		}
		
		vector<pair<ll, ll>> prefix;
		ll mx = -inf_ll, sum = 0;
		for(int x=0;x<n;x++){
			sum += data[x];
			if(sum > mx){
				prefix.push_back({sum, x});
			}
			mx = max(mx, sum);
		}
						
		for(int x=0;x<m;x++){			
			ll tmp = lower_bound(prefix.begin(), prefix.end(), make_pair(query[x] * 1ll, -1ll)) - prefix.begin();
			
			if(tmp >= 0 && tmp < prefix.size()){
				query[x] = prefix[tmp].second;
			} else {
				if(sum <= 0 && query[x] > mx){
					query[x] = -1;
				} else {
					tmp = (query[x]-prefix.back().first+sum-1)/sum;
					
					ll cur = query[x]-tmp*sum;
					if(cur == 0){
						query[x] = tmp*n-1;
					} else {
						pair<ll, ll> p = *lower_bound(prefix.begin(), prefix.end(), make_pair(cur, -1ll));
						
						query[x] = tmp*n+p.second;	
					}
				}
			}
		}
		
		for(int x=0;x<m;x++){
			if(x > 0) cout << " ";
			cout << query[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

