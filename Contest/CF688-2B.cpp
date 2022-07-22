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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll sum = 0;
		ll b[n];
		for(int x=1;x<n;x++){
			ll diff = a[x]-a[x-1];
			
			b[x] = diff;
			sum += abs(diff);
		}
		
		ll ans = inf_ll;
		for(int x=0;x<n;x++){
			if(x == 0){
				ans = min(ans, sum-abs(b[x+1]));
			} else if(x == n-1){
				ans = min(ans, sum-abs(b[x]));
			} else {
				ans = min(ans, sum-abs(b[x])-abs(b[x+1])+abs(a[x+1]-a[x-1]));
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

