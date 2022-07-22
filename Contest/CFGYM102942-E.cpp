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

const int maxN = 1e5 + 5;
ll fac[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	fac[0] = fac[1] = 1;
	
	for(int x=2;x<maxN;x++){
		fac[x] = (x*fac[x-1])%mod;
	}
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		ll ans = 0;
		int start = 1;
		for(int x=0;x<n;x++){
			if(s[x] >= '0' && s[x] <= '9'){
				ans += 
			}
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

