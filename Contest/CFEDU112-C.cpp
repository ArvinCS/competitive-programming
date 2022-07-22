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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n][2];
		for(int x=0;x<2;x++){
			for(int y=0;y<n;y++){
				cin >> a[y][x];
			}
		}
		
		ll prefix[n][2], sum[2];
		sum[0] = sum[1] = 0;
		
		for(int x=0;x<2;x++){
			for(int y=0;y<n;y++){
				prefix[y][x] = (y > 0 ? prefix[y-1][x] : 0);
				prefix[y][x] += a[y][x];
				
				sum[x] += a[y][x];
			}
		}
		
		ll ans = inf_ll;
		for(int x=0;x<n;x++){
			ll top = sum[0]-prefix[x][0];
			ll bot = (x > 0 ? prefix[x-1][1] : 0);
			
			ans = min(ans, max(top, bot));
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

