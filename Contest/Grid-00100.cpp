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
		int n, k;
		cin >> n >> k;
		
		if(k == 0 || k % n == 0){
			cout << "0\n";
		} else {
			cout << 2*((k+n-1)/n - k/n) << "\n";
		}
		
		us ans[n][n];
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				if(k >= y*n+x+1){
					ans[x][(x+y) % n] = 1;
				} else {
					ans[x][(x+y) % n] = 0;
				}
			}
		}
		
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++) cout << ans[x][y];
			cout << "\n";
		}
	}
	
    return 0;
}

