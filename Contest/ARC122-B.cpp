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

	int n;
	cin >> n;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		data[x] *= 10;
	}
	
	sort(data, data+n);
	
	ll prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = (x > 0 ? prefix[x-1] : 0) + data[x];
	}
	
	ll ans = inf_ll;
	for(int x=0;x<n;x++){
		auto it = upper_bound(data, data+n, data[x]);
		int idx = it - data;
		
		ans = min(ans, n*data[x]/2 + prefix[n-1] - max(n-idx, 0)*data[x] - (idx > 0 ? prefix[idx-1] : 0));
//		cout << ans << "\n";
	}
	cout << fixed << setprecision(7) << ans*1.0/(10*n) << "\n";
	
    return 0;
}



