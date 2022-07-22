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
		
		string b;
		cin >> b;
		
		if(n == 1){
			cout << "1\n";
			continue;
		}
		
		int ans[n];
		ans[0] = 1;
		for(int x=1;x<n;x++){
//			cout << (b[x]+1) << " " << (b[x-1]+ans[x-1]) << "\n";
			if((b[x]+1) == (b[x-1]+ans[x-1])){
				ans[x] = 0;
			} else {
				ans[x] = 1;
			}
		}
		
		for(int x=0;x<n;x++){
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

