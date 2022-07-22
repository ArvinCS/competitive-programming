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
	
	ll n, k;
	cin >> n >> k;
	
	vector<pair<ll, ll>> v;
	for(int x=0;x<n;x++){
		ll a, b;
		cin >> a >> b;
		
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	ll prv = 0, cur = k;
	for(int x=0;x<v.size();x++){
		ll a = v[x].first, b = v[x].second;
		if(a-prv <= cur){
			cur -= a-prv;
			cur += v[x].second;
			
			prv = a;
		} else {
			break;
		}
	}
	cout << prv+cur << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

