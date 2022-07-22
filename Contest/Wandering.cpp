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
	
	int n;
	cin >> n;
	
	ll data[n], prefix[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		prefix[x] = data[x] + (x > 0 ? prefix[x-1] : 0);	
	}
	
	ll best[n];
	for(int x=0;x<n;x++){
		best[x] = prefix[x];
		if(x > 0) best[x] = max(best[x], best[x-1]);
	}
	
	ll ans = 0, tmp = 0;
	for(int x=0;x<n;x++){
		ans = max(ans, tmp + best[x]);
		tmp += prefix[x];
	}
	
	cout << ans << "\n";
    return 0;
}

