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

	int n, m;
	cin >> n >> m;
	
	ll grid[n][m];
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			cin >> grid[x][y];
		}
	}
	
	ll ans = 0;
	for(int y=0;y<m;y++){
		ll best = inf_ll;
		
		map<ll, ll> mp;
		for(int x=0;x<n;x++){
			ll num = grid[x][y] - (y+1);
			if(num % m == 0 && grid[x][y] <= (n-1)*m+(y+1)){
				ll place = num/m;
				ll rotate = 0;
				if(place > x){
					rotate = (x+n)-place;
				} else {
					rotate = x-place;
				}
				
				mp[rotate]++;
			}
		}
		
		for(auto m : mp){
			best = min(best, m.first+(n-m.second));
		}
		best = min(best, n-mp[0]);
		
		ans += best;
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

