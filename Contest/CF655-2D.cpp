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

	int n;
	cin >> n;
	
	ll a[2*n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[n+x] = a[x];
	}
	
	if(n == 1){
		cout << a[0] << "\n";
		return 0;
	}
	
	ll table[2*n+2];
	table[0] = table[1] = 0;
	
	ll ans = 0;
	for(int x=2;x<2*n+2;x++){
		table[x] = table[x-2] + a[x-2];
	}
	
	for(int x=n;x<=2*n;x++){
		ans = max(ans, table[x+1]-table[x-n]);
	}
	cout << ans << "\n";
    return 0;
}

