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

const int maxK = 2*1e5 + 5;

ll ans[maxK];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		ll n, k;
		cin >> n >> k;
		
		for(int x=0;x<k;x++){
			ans[x] = x+1;
		}
		
		reverse(ans+2*k-n-1, ans+k);
		
		for(ll x=0;x<k;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";	
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

