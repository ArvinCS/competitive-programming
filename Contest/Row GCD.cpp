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
	
	int n, m;
	cin >> n >> m;
	
	ll a[n], b[m];
	for(int x=0;x<n;x++) cin >> a[x];
	for(int x=0;x<m;x++) cin >> b[x];
	
	sort(a, a+n);
	
	ll tmp = -1;
	if(n > 1){
		tmp = a[1] - a[0];
		for(int x=2;x<n;x++){
			tmp = __gcd(tmp, a[x]-a[x-1]);
		}
	}
	
	for(int x=0;x<m;x++){
		if(x > 0) cout << " ";
		if(tmp >= 0) cout << __gcd(a[0] + b[x], tmp);
		else cout << a[0] + b[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

