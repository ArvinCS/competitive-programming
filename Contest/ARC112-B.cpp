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

pair<ll ,ll> range(ll n, ll m){
	ll a = m/2;
	if(m&1){
		return {-n-a, -n+a};
	} else {
		if(m == 0) return {n, n};
		return {n-a, n+a-1};
	}
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	pair<ll, ll> a = range(n, m);
	pair<ll, ll> b = range(n, m-1);

	cout << (a.second-a.first+1) + (b.second-b.first+1) - max(0ll, min(a.second,b.second)-max(a.first,b.first)+1) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

