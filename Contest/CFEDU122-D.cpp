#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool customSort(pair<ll, ll> a, pair<ll, ll> b){
	return a.first*b.second > b.first*a.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		int a[n];
		fill(a, a+n, 1);
		
		int b[n];
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		ll c[n];
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		vector<pair<ll, ll>> v;
		for(int x=0;x<n;x++){
			ll cnt = 0;
			for(int y=1;y<=b[x];y++){
				while(a[x]/y != 0 && a[x]+a[x]/y <= b[x]){
					a[x] += a[x]/y;
					cnt++;
				}
			}
			
			v.push_back({c[x], cnt});
		}
		
		sort(v.begin(), v.end(), customSort);
		
		ll ans = 0;
		for(int x=0;x<v.size();x++){
			if(v[x].second <= k){
				k -= v[x].second;
				ans += v[x].first;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

