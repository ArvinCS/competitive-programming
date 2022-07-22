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
		ll n, m, x;
		cin >> n >> m >> x;
		
		ll pos = x/n * n + x%n;
		cout << (pos%n == 0 ? n-1 : pos%n - 1) * m + (pos+n-1)/n << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

