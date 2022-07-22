#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	map<ll, int> mp;
	mp[0] = 1;
	
	ll ans = 0, sum = 0;
	for(int x=0;x<n;x++){
		sum += a[x];
		ans += mp[sum-k];
		
		mp[sum]++;
	}
	
	cout << ans << "\n";
    return 0;
}

