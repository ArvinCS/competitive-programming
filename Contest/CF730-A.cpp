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

	int t;
	cin >> t;
	
	while(t--){
		ll a, b;
		cin >> a >> b;
		
		ll ans = abs(a-b);
		
		if(ans == 0){
			cout << "0 0\n";
			continue;
		}
		
		ll mn1 = min(a, b)/ans * ans, mn2 = (min(a,b)+ans-1)/ans * ans;
		
		cout << ans << " " << min(min(a,b)-mn1, mn2-min(a,b)) << "\n";
	}

    return 0;
}

