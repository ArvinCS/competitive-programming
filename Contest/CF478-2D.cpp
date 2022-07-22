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

	int n, a, b;
	cin >> n >> a >> b;
	
	tuple<ll, ll, ll> g[n];
	for(int x=0;x<n;x++){
		ll i, j ,k;
		cin >> i >> j >> k;
		
		g[x] = make_tuple(i, j, k);
	}
	
	ll ans = 0;
	map<ll, int> mp;
	map<pair<ll, ll>, int> cnt;
	for(int x=0;x<n;x++){
		ll tmp = (a*get<1>(g[x]) - get<2>(g[x]));
		
		ans += mp[tmp] - cnt[{get<1>(g[x]), get<2>(g[x])}];
		
		cnt[{get<1>(g[x]), get<2>(g[x])}]++;
		mp[tmp]++;
	}
	
	cout << ans*2 << "\n";
    return 0;
}

