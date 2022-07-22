#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 3e5 + 5;
const int maxA = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	map<pair<ll, ll>, int> mp;
	
	int ans = 1;
	for(int x=1;x<n;x++){
		ll mn = (a[x]+maxA+x-1)/x;
		ll mx = (maxA+x-1)/x;
		
		for(ll y=-max(mx, mn);y<=max(mx, mn);y++){
			auto ref = &mp[{a[x]+x*1ll*(-y), y}];
			ref++;
			
			ans = max(ans, ref);
		}
	}
	
	cout << n-ans << "\n";
    return 0;
}

