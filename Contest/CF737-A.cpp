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
		
		ll a[n], left = 0, right = 0;
		for(int x=0;x<n;x++){
			cin >> a[x];
			right += a[x];
		}
		
		sort(a, a+n);
		
		double ans = -inf_ll;
		for(int x=0;x<n-1;x++){
			right -= a[x];
			left += a[x];
			
			ans = max(ans, left*1.0/(x+1) + right*1.0/(n-x-1));
		}
		
		cout << fixed << setprecision(7) << ans << "\n";
	}

    return 0;
}
