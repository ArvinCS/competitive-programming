#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	ll b[n];
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	ll a[n];
	fill(a, a+n, 0);
	
	pair<ll, ll> lazy[n+1];
	fill(lazy, lazy+n+1, make_pair(0, 0));
	
	ll ans = 0, mx = 0;
	ll cnt = 0, cur = 0;
	for(int x=n-1;x>=0;x--){
		cur += lazy[x].first;
		cnt += lazy[x].second;
		
		a[x] += cnt*(x+1)-cur;
		
		ll need = max(0ll, (b[x]-a[x]+min(x+1, k)-1)/min(x+1, k));
		
		if(x-k >= 0){
			lazy[x-k].first -= need*max(0, x-k+1);
			lazy[x-k].second -= need;
		}
		
		a[x] += need*max(0, x-k+1);
		cur += need*max(0, x-k+1);
		cnt += need;
		ans += need;
	}
	
	cout << ans << "\n";
    return 0;
}

