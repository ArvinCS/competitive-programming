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
		int n, k;
		cin >> n >> k;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll ans = -inf_ll;
		for(int x=n-1;x>=max(0, n-205);x--){
			for(int y=x-1;y>=max(0, x-205);y--){
				ans = max(ans, (x+1)*1ll*(y+1) - k *1ll* (a[x]|a[y]));
			}
		}
		cout << ans << "\n";
	}

    return 0;
}
