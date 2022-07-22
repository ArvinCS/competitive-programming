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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		sort(b, b+n);
		sort(a, a+n);
		
		ll suffix[n][2];
		for(int x=n-1;x>=0;x--){
			suffix[x][0] = (a[x] + (x+1 < n ? suffix[x+1][0] : 0));
			suffix[x][1] = (b[x] + (x+1 < n ? suffix[x+1][1] : 0));
		}
		
		ll left = 0, right = 1000000, ans = inf_ll;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			ll sum = mid*100, sum2 = suffix[max(n-(n+mid-(n+mid)/4), 0ll)][1];
			
			ll leftBound = (n+mid) - (n+mid-(n+mid)/4);
			if(leftBound < n){
				sum += suffix[leftBound][0];
			}
			
			if(sum >= sum2){
				ans = min(ans, mid);
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

