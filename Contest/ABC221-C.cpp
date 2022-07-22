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

ll solve(int idx, vector<ll> v, ll a, ll b){
	if(idx == v.size()){
		return a*b;
	}
	
	a *= 10;
	a += v[idx];
	ll ans = solve(idx+1, v, a, b);
	
	a /= 10;
	b *= 10;
	b += v[idx];
	ans = max(ans, solve(idx+1, v, a, b));
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	vector<ll> v;
	while(n > 0){
		v.push_back(n%10);
		n /= 10;
	}
	
	sort(v.rbegin(), v.rend());
	
	cout << solve(0, v, 0, 0) << "\n";
    return 0;
}

