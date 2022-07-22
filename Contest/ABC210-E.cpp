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
	
	ll n, m;
	cin >> n >> m;
	
	pair<ll, ll> a[m];
	for(int x=0;x<m;x++){
		cin >> a[x].second >> a[x].first;
	}
	
	sort(a, a+m);
	
	int pos = 0;
	
	ll range = 0;
	ll ans = 0;
	while(pos < m){
		if(__gcd(a[pos].second, n) != n){
			range = __gcd(a[pos].second, n);
			ans += a[pos].first*(n-range);
			break;
		}
		pos++;
	}
	
	if(range == 0){
		cout << "-1\n";
		return 0;
	}
	
//	cout << a[0].first << " " << range << " " << ans << "\n";
	for(int x=pos+1;x<m;x++){
		if(range == 1) break;
		
		ll jump = __gcd(a[x].second, range);
		if(jump == range) continue;
		
		ans += a[x].first*(range-jump);
		range = jump;
	}
	
	if(range == 1){
		cout << ans << "\n";
	} else {
		cout << "-1\n";
	}
    return 0;
}

