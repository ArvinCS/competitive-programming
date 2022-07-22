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

struct Service {
	ll begin, end, cost;
};

bool customSort(Service a, Service b){
	if(a.begin == b.begin){
		if(a.end == b.end) return a.cost < b.cost;
		return a.end < b.end;
	}	
	return a.begin < b.begin;
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	
	ll plan;
	int n;
	cin >> n >> plan;

	vector<pair<ll, ll>> v;
	for(int x=0;x<n;x++){
		ll a, b, c;
		cin >> a >> b >> c;
		
		v.push_back({a-1, c});
		v.push_back({b, -c});
	}
	
	sort(v.begin(), v.end());
	
	ll ans = 0, tmp = 0, day = 0;
	for(int x=0;x<v.size();x++){
		if(v[x].first != day){
			ans += min(plan, tmp)*(v[x].first-day);
			day = v[x].first;
		}
		tmp += v[x].second;
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

