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

const int maxN = 1e5 + 5;

ll pw[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	pw[0] = 1;
	for(int x=1;x<maxN;x++){
		pw[x] = (2ll*pw[x-1]) % mod;
	}
	
	int n;
	cin >> n;
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		ll tmp = (pw[x] - 1 + mod) % mod;
		ll tmp2 = (pw[n-x-1] - 1 + mod) % mod;
		
		ans += tmp * data[x] - tmp2 * data[x];
//		cout << ans << "\n";
	}
	
	cout << ans << "\n";
    return 0;
}

