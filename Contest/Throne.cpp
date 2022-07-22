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
		ll n, s, k;
		cin >> n >> s >> k;
		
		bool found = false;
		ll throne = n-s+1;
		ll tmp = abs((throne-1)%k - n%k);
		
		if(tmp == 0) cout << "-1\n";
		else cout << (tmp*n+throne-1)/k << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

