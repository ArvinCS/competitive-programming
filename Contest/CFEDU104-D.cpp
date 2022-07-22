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
		
		ll cur = 1, ans = 0;
		for(ll x=4;x<=n;x+=4){
			if(cur+x <= n){
				ans++;
			} else {
				break;
			}
			cur += x;
		}
//		for(int x=1;x<10000;x++){
//			for(int y=1;y<10000;y++){
//				for(int z=1;z<10000;z++){
//					if(x*x+y*y == z*z){
//						cout << x << " " << y << " " << z;
//						if(z+y == x*x){
//							cout << " VALID\n";
//						} else {
//							cout << " NOT VALID\n";
//						}
//					}
//				}
//			}
//		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

