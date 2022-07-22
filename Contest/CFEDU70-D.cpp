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
		ll n;
		cin >> n;
		
		if(n <= 99998){
			for(ll x=1;x<=n;x++) cout << 1;
			cout << "337\n";
			continue;
		}
		
		for(ll x=2;x<=n;x++){			
			ll cnt = ((x+2) * (x+1))/2;
			ll length = 4+x+(n-cnt)+1;
			
			if(length <= 100000 && n-cnt > 0){
				cout << 1;
				for(ll y=1;y<=x;y++) cout << 3;
				for(ll y=1;y<=n-cnt;y++) cout << 1;
				cout << 33;
				cout << 7 << "\n";
				
				break;
			}
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

