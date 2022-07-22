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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	ll n, k;
	cin >> n >> k;
	
	for(ll i=1;i<=k;i++){
		if(n%200 == 0){
			n /= 200;
			continue;
		}
		n = (n * 1000ll + 200);
	}
	
	cout << n << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

