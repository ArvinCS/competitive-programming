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

const int maxN = 1e7 + 5;

ll table[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	for(ll x=a;x<=b;x++){
		table[x+b]++;
		table[x+c+1]--;
	}
	
	for(ll x=1;x<maxN;x++){
		table[x] += table[x-1];
	}
	for(ll x=1;x<maxN;x++){
		table[x] += table[x-1];
	}
	
	ll ans = 0;
	for(ll x=c;x<=d;x++){
		ans += table[maxN-1]-table[x];
	}
	cout << ans << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

