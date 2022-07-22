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
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll ans = 0;
		for(int i=0;i<n;i++){
			int left = max(i-5, 0);
			for(int x=left;x<i;x++){
				for(int y=x+1;y<i;y++){
					for(int z=y+1;z<=i;z++){ // ax ay az
						if(a[x] <= a[y] && a[y] <= a[z]){
							left = max(left, x+1);
						}
						if(a[x] >= a[y] && a[y] >= a[z]){
							left = max(left, x+1);
						}
					}
				}
			}
			
			ans += i-left+1;
		}
		
//		ans += left;
		cout << ans << "\n";
	}
    return 0;
}
