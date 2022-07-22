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
	
	for(int i=1;i<=t;i++){
		ll l, r, m;
		cin >> l >> r >> m;
		
		ll ans = 0;
		for(ll x=l;x<=l+4&&x<=r;x++){
			ll rem1 = (x-1)%4;
			ll left = 0;
			
			if(rem1 == 0){
				left = x-1;
			} else if(rem1 == 1){
				left = 1;
			} else if(rem1 == 2){
				left = x;
			} else {
				left = 0;
			}
			
			for(ll y=r;y>=r-4&&y>=x;y--){
				ll rem2 = y%4;
				ll right = 0;
				
				if(rem2 == 0){
					right = y-1;
				} else if(rem2 == 1){
					right = 1;
				} else if(rem2 == 2){
					right = y;
				} else {
					right = 0;
				}
				
				if((right^left) <= m){
					ans = max(ans, y-x+1);
				}
			}
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

