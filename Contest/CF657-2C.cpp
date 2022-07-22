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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		ll mxB = 0;
		vector<pair<ll, ll>> v, w;
		for(ll x=0;x<m;x++){
			ll a, b;
			cin >> a >> b;
			
			v.push_back({a, b});
			mxB = max(mxB, b);
		}
		
		sort(v.begin(), v.end());
		
		ll suffix[m];
		suffix[m-1] = v[m-1].first;
		for(ll x=m-2;x>=0;x--){
			suffix[x] = suffix[x+1] + v[x].first;
		}
		
		ll ans = 0;
		for(ll x=0;x<m;x++){
			auto it = lower_bound(v.begin(), v.end(), make_pair(v[x].second, -1ll));

			ll idx = (it - v.begin());
//			cout << v[x].second << " -> " << idx << "\n";
			if(idx == m){
				ans = max(ans, v[x].first+v[x].second*(n-1));
			} else {
				ll cnt = m-idx;
				if(cnt >= n){
					ans = max(ans, suffix[max(idx, m-n)]);
				} else {
					bool tmp = (idx <= x);
					ans = max(ans, suffix[max(idx, m-n)]+(tmp?0:v[x].first)+v[x].second*max(n-cnt-!tmp, 0ll));
				}
			}
		}
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar
