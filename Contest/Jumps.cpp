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
		int x;
		cin >> x;
		
		int ans = inf_int;
		for(int start=0;start<2*x;start++){
			int cur = -start;
			for(int y=start+1;y<=2*x;y++){
				cur += y;
				
				if(cur >= x){
					ans = min(y+cur-x, ans);
//					cout << start << " " << cur << " " << y << "\n";
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

