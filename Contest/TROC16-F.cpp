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

const int maxN = 2e5 + 5, mask = 1050000;

vector<int> adj[25];
pair<ll, ll> tower[25];
pair<ll, ll> table[25][mask];
ll cost[25];
ll bitmask[maxN];
ll ans[maxN];
ll n, m, r;

void solve(int idx, ll curbit, ll c){
	if(idx == m){
		int cnt = 0;
		for(int x=0;x<m;x++){
			ll 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	cin >> n >> m >> r;
	
	pair<ll, ll> data[n];
	for(int x=0;x<n;x++){
		cin >> data[x].first >> data[x].second;
	}
	
	for(int x=0;x<m;x++){
		cin >> tower[x].first >> tower[x].second >> cost[x];	
	}
	
	for(int x=0;x<n;x++){
		ll bit = 0;
		for(int y=0;y<m;y++){
			ll dist = pow(tower[y].first-data[x].first, 2ll) + pow(tower[y].second-data[x].second, 2ll);
			if(dist <= r*r){
				adj[y].push_back(x);
				bit |= (1<<y);
			}
		}
		bitmask[x] = bit;
	}
	
	fill(ans, ans+n, inf_ll);
	for(int x=0;x<m;x++){
		ll bit = (1 << x);
		table[1][bit] = {adj[x].size(), cost[x]};
		ans[table[1][bit].first] = min(ans[table[1][bit].first], table[1][bit].second);
	}
	for(int x=2;x<=m;x++){
		
	}
	
	ll mn = inf_ll;
	for(int x=n;x>=1;x--){
		if(ans[x] != inf_int){
			mn = min(ans[x], mn);
		}
		ans[x] = mn;
	}
	
	for(int x=1;x<=n;x++){
		cout << (ans[x] == inf_ll ? -1 : ans[x]) << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

