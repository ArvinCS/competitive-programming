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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pair<ll, ll> monster[n];
		for(int x=0;x<n;x++){
			cin >> monster[x].first >> monster[x].second;
		}
		
		ll data[n];
		ull ans = inf_ll, sum = 0;
		for(int x=0;x<n;x++){
			data[(x+1)%n] = max(monster[(x+1)%n].first - monster[x].second, 0ll);
			sum += data[(x+1)%n];
		}		
		for(int x=0;x<n;x++){
			ans = min(ans, sum-data[x]+monster[x].first);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

