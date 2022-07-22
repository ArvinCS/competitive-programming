#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

map<ll, ll> mp;

ll solve(ll x){
	if(mp.find(x) != mp.end()) return mp[x];
	
	return mp[x] = (solve(x/2) * solve((x+1)/2) % mod);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	mp[1] = 1;
	mp[2] = 2;
	mp[3] = 3;
	mp[0] = 1;
	
	cout << solve(n) << "\n";
    return 0;
}

