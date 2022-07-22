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
	
	int n;
	cin >> n;
	
	if(n <= 1){
		cout << "0\n";
	} else if(n % 2 == 0){
		cout << ((2*n)/4) * ((2*n)/4) * 4 << "\n";
	} else if(n&1){
		cout << ((2*n)/4) * ((2*n)/4) * 4 + ((2*n)/2) + ((2*n-1)/2) - 1 << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

