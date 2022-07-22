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
	
	ll a[n], b[n];
	for(int x=0;x<n;x++) cin >> a[x];
	for(int x=0;x<n;x++) cin >> b[x];
	
	ll product = 0;
	for(int x=0;x<n;x++){
		product += a[x] * b[x];
	}
	
	if(product == 0){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

