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
		
		ll a[n], b[n], c[n];
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
		}
		
		ll ans = 0, sum = abs(b[1]-a[1])+1, prev = 0, last = 1;
		for(int x=1;x<n;x++){
			sum -= prev;
			if(x > last) sum += min(a[x], b[x]) + (c[x-1] - max(a[x], b[x]) + 1);
			sum += c[x];
			prev = c[x];
			
			if(sum < abs(b[x]-a[x])+1 + c[x]){
				sum = abs(b[x]-a[x])+1 + c[x];
			}
				
			ans = max(ans, sum);
			
			if(x+1 < n){
				if(a[x+1] == b[x+1]){
					sum = 1;
					prev = 0;
					last = x+1;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

