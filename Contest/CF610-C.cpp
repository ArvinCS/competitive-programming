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

	us t;
	cin >> t;
	
	while(t--){
		ll n, m, a, b;
		cin >> n >> m >> a >> b;
		
		ll cnt1 = 0, cnt2 = 0;
		pair<ll, bool> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].second;
			if(p[x].second) cnt2++;
			else cnt1++;
		}
		
		for(int x=0;x<n;x++){
			cin >> p[x].first;
		}
		
		sort(p, p+n);
		
		ll ans = 0, time = 0;
		for(ll x=0;x<=n;x++){
			if(x > 0){
				time += (p[x-1].second ? b : a);
				if(p[x-1].second) cnt2--;
				else cnt1--;
			}
			
//			cout << x << " ---> " << time << "\n";
			ll best = x;
			if(time > m) break;

			if(x < n){
				ll left = p[x].first-time-1;
				if(left >= 0){
					ll tmp = min(left/a, cnt1);
					best += tmp;
					left -= tmp*a;
//					cout << x << " -> " << best << " " << tmp << " " << left << "\n";
					tmp = min(left/b, cnt2);
					best += tmp;
					left -= tmp*b;
				} else {
					continue;
				}
			}
			ans = max(ans, best);
		}

		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

