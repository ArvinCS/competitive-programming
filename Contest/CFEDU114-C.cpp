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

const int maxN = 2e5 + 5;

ll a[maxN], sum = 0;
pair<ll, ll> d[maxN];
vector<ll> v;

ll calc(int idx, int x){
	ll cost = 0;
	
	cost += max(d[x].first - v[idx], 0ll);
	cost += max(d[x].second - (sum - v[idx]), 0ll);
	
	return cost;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n;
	cin >> n;
	
	sum = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += a[x];
		v.push_back(a[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int m;
	cin >> m;
	
	for(int x=0;x<m;x++){
		cin >> d[x].first >> d[x].second;
	}
	
	int sz = v.size();
	for(int x=0;x<m;x++){
		int idx = lower_bound(v.begin(), v.end(), d[x].first) - v.begin();
		
		ll cost = calc(idx, x);
		for(int y=max(0, idx-500);y<min(sz, idx+501);y++){
			cost = min(cost, calc(y, x));
		}
		
		cout << cost << "\n";
	}
    return 0;
}
