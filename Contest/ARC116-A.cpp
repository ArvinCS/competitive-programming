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

	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		if(n&1){
			cout << "Odd\n";
		} else if((n/2)&1){
			cout << "Same\n";	
		} else {
			cout << "Even\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

