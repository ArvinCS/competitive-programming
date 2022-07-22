#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	map<ll, ll> mp;
	ll ans = 1, sum = 0, cur = 1, cnt = a[0];
	mp[cnt] = 1;
	for(int x=1;x<n;x++){
		cnt += a[x];
		
		ans += cur-mp[cnt];
		sum += cur-mp[cnt];
		
		mp[cnt] = cur;
		cur += sum;
		
		cout << x << " = " << ans << "\n";
	}
	cout << ans << "\n";
    return 0;
}

