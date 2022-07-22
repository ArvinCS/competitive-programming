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

const ll neg = -1e12, pos = 1e12;
const int maxN = 1e5;

pair<ll, ll> hor[maxN], ver[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			cin >> hor[x].first >> hor[x].second;
			ver[x].first = hor[x].second; ver[x].second = hor[x].first;
		}
		
		sort(hor, hor+n);
		sort(ver, ver+n);
		
		ll ans = 0, cnt = 1;
		for(int x=0;x<n;x++){
			if(x+1 < n && hor[x].first == hor[x+1].first && hor[x].second == hor[x+1].second){
				cnt++;
				continue;
			}
			
			ll best = 0;
			ll l = lower_bound(hor, hor+n, make_pair(hor[x].first, neg)) - hor, r = upper_bound(hor, hor+n, make_pair(hor[x].first, pos)) - hor;
			best += r-l;
			
//			cout << "bef: " << best << "\n";
			l = lower_bound(ver, ver+n, make_pair(hor[x].second, neg)) - ver;
			r = upper_bound(ver, ver+n, make_pair(hor[x].second, pos)) - ver; 
			best += r-l;
			
//			cout << r << " " << l << " " << x << " " << best << "\n";
			ans = max(ans, best-cnt*2);
			cnt = 1;
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

