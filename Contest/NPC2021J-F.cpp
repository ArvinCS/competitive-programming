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

const ll inv = 500000004;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, s;
	cin >> n >> s;
	
	n %= mod;
	s %= mod;
	
	ll total = (n*s) % mod;
	cout << ((total*(total+1) % mod) * inv % mod - (n*(n-1) % mod) * inv % mod + mod) % mod << "\n";
    return 0;
}

