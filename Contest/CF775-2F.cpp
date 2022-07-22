#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	ll a[3][n];
	for(int x=0;x<3;x++){
		for(int y=0;y<n;y++){
			cin >> a[x][y];
		}
	}
	
	vector<int> v[n];
	int l[q], r[q];
	ll k[q];
	for(int x=0;x<q;x++){
		cin >> l[x] >> r[x] >> k[x];
		l[x]--; r[x]--;
		
		if(l[x] > 0) v[l[x]-1].push_back(x);
		v[r[x]].push_back(x);
	}
	
	ll suffix[n];
	for(int x=n-1;x>=0;x--){
		if(x < n-1) suffix[x] = suffix[x+1];
		else suffix[x] = 0;
		
		suffix[x] += a[2][x];
	}
	
	bool active[n];
	fill(active, active+n, false);
	
	multiset<ll> st;
	
	pair<ll, ll> dp[n+1];
	fill(dp, dp+n+1, make_pair(-1e18, 1e18));
	
	for(int x=n-1;x>=0;x--){
		for(auto idx : v[x]){
			if(active[idx]){
				st.erase(st.find(k[idx]));
			} else {
				st.insert(k[idx]);
			}
			active[idx] ^= 1;
		}
		
		if(st.size() == 0) continue;
		
		ll mn = *st.begin();
		dp[x] = max(dp[x+1]+a[1][x], a[1][x]+suffix[x]-mn);
		cout << x << " = " << dp[x] << " " << dp[x+1]+a[1][x] << " " << a[1][x]+suffix[x]-mn << " " << mn << "\n";
	}
	
	ll ans = -1e18;
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += a[0][x];
		ans = max(ans, sum+dp[x]);
		cout << x << " -> " << ans << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

