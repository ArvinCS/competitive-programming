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

	ll n, d, m;
	cin >> n >> d >> m;
	
	ll data[n];
	vector<ll> a, b;
	for(int x=0;x<n;x++){
		cin >> data[x];
		if(data[x] > m){
			a.push_back(data[x]);
		} else {
			b.push_back(data[x]);
		}
	}
	
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	
	for(ll x=1;x<b.size();x++){
		b[x] += b[x-1];
	}
	
	ll ans = 0, cnt = 0, sz = b.size();
	for(ll i=0;i<=a.size();i++){
		ll days = (max(i-1, 0ll) * (d+1) + (i > 0));
		if(days > n) break;
		if(i > 0) cnt += a[i-1];
		
		ll tmp = 0;
		ll rem = n - days;
		if(rem > 0 && sz > 0){
			tmp = b[min(rem, sz)-1];
		}
		
		ans = max(ans, cnt+tmp);
	}
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

