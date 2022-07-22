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
	
	ll n, m, s;
	cin >> n >> m >> s;
	
//	vector<tuple<ll, ll, ll>> data;
	vector<pair<ll, ll>> v[n+1];
	for(int x=0;x<m;x++){
		ll a, b, c;
		cin >> a >> b >> c;
		
//		data.push_back(make_tuple(a, b, c));
		v[a].push_back({b, c});
	}
		
	ll ans = n*s;
	ll table[n+1];
	table[0] = 0;
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	
	for(ll x=1;x<=n;x++){
		for(int y=0;y<v[x].size();y++){
			pair<ll, ll> p = v[x][y];
			pq.push(make_pair(table[x-1] + p.second, p.first));
		}
		while(!pq.empty()){
			if(pq.top().second < x){
				pq.pop();
			} else {
				break;
			}
		}
		if(pq.empty()){
			table[x] = table[x-1] + s;
		} else {
			table[x] = min(table[x-1] + s, pq.top().first);
		}
	}

	cout << table[n] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

