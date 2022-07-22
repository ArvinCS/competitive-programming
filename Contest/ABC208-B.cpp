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

	ll n;
	cin >> n;
	
	ll fac = 1, ans = 0;
	for(ll x=2;x<=11;x++) fac *= x;
	for(ll x=11;x>=1;x--){
		while(fac <= n){
			n -= fac;
			ans++;
		}
		fac /= x;
	}
	
	cout << ans << "\n";
    return 0;
}

