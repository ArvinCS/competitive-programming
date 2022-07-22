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
		ll k;
		cin >> n >> k;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		ll sum = 0;
		for(int x=0;x<n;x++){
			sum += a[x];
		}
		
		if(sum <= k){
			cout << "0\n";
			continue;
		}
		
		ll ans = max(0ll, sum-k), cur = a[0];
		for(int x=n-1;x>=1;x--){
			cur += a[x];
			
			int cnt = n-x+1;
			ll pivot = (k-sum+cur)/cnt;
			
			if((k-sum+cur) % cnt != 0 && (k-sum+cur) < 0){
				pivot--;
			}
			
			ans = min(ans, max(0ll, a[0]-pivot)+cnt-1);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}
