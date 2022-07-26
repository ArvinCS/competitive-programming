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
		int n;
		cin >> n;
		
		ll sum = 0;
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			sum += a[x];
		}
		
		sort(a, a+n);
		
		double mean = sum*1.0/n;
		
		ll ans = 0;
		map<double, int> mp;
		for(int x=0;x<n;x++){
			double res = a[x]-mean;
			
			ans += mp[-res];
			mp[res]++;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

