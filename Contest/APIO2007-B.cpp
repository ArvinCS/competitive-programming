#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	ll s[n];
	for(int x=0;x<n;x++){
		cin >> s[x];
	}
	
	for(int x=n-1;x>0;x--){
		s[x] -= s[x-1];
	}
	
	pair<ll, ll> table[n][2];
		
	ll left = 0, right = 1e9;
	pair<ll, ll> ans = {-1e18, -1e18};
	
	while(left <= right){
		ll mid = (left+right) >> 1;
		
		table[0][0] = table[0][1] = {0, 0};
		for(int x=1;x<n;x++){
			table[x][1] = table[x-1][0];
			table[x][0] = min(table[x-1][0], {table[x-1][1].first+s[x]-mid, table[x-1][1].second+1});
		}
		
		ll val = table[n-1][0].first;
		int cnt = table[n-1][0].second;
		
		if(cnt <= k){
			ans = {val, mid};
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	
	cout << ans.first+ans.second*k << "\n";
    return 0;
}

