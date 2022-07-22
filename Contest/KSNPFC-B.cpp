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

	int n, k;
	cin >> n >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	sort(a, a+n);
	
	vector<int> v;
	for(int x=1;x<n;x++){
		v.push_back(a[x-1]-a[x]);
	}
	
	sort(v.begin(), v.end());
	
	ll ans = a[n-1] - a[0];
	for(int x=0;x<k-1;x++){
		ans += v[x];
	}
	
	cout << ans << "\n";
    return 0;
}

