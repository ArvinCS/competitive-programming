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

	us t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		bool prime = true;
		for(ll x=2;x*x<=m;x++){
			if(m % x == 0){
				prime = false;
				break;
			}
		}
		
		if(prime){
			cout << m-1 << "\n";
			continue;
		}
		
		if(__gcd(n, m) == 1){
			if(__gcd(n, m) == 1){
				
			} else {
				
			}
		} else {
			cout << (n+m-1)/n - 1 << "\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

