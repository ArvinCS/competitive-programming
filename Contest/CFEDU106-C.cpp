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
		
		ll cost[n+1];
		for(int x=1;x<=n;x++){
			cin >> cost[x];
		}
		
		ll odd = cost[1], even = cost[2];
		ll minodd = cost[1], mineven = cost[2];
		
		ll tmp1 = cost[1]*n, tmp2 = cost[2]*n;
		ll ans = tmp1+tmp2;
		
		ll oddlength = 1, evenlength = 1;
		for(int x=3;x<=n;x++){
			ll length = (x-1)/2;
			if(n-length <= 0) break;
			
			if(x % 2 == 1){
				minodd = min(minodd, cost[x]);
				odd += cost[x];
				oddlength++;
			} else {
				mineven = min(mineven, cost[x]);
				even += cost[x];
				evenlength++;
			}
			
			tmp1 = odd + minodd * (n-oddlength);
			tmp2 = even + mineven * (n-evenlength);
			
			ans = min(ans, tmp1+tmp2);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

