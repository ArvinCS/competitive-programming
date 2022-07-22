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
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	ll suffix[n];
	suffix[n-1] = data[n-1];
	
	for(int x=n-2;x>=0;x--){
		suffix[x] = suffix[x+1] + data[x];
	}
	
	ll ans = 0;
	for(int x=0;x<n-1;x++){
		ans += abs(data[x] * (n-x-1) - suffix[x+1]);
	}
	
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

