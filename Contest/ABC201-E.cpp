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

int n;
vector<pair<int, ll>> adj[maxN];
ll dist[maxN];

void dfs(int curNode, int prvNode, ll cost){
	dist[curNode] = cost;
	
	for(auto p : adj[curNode]){
		if(p.first != prvNode){
			dfs(p.first, curNode, cost^p.second);
		}
	}
}

ll mulmod(ll x, ll y){
	ll ans = 0;
	x %= mod;
	
	while(y > 0){
		if(y&1) ans = (ans + x) % mod;
		
		y >>= 1;
		x = (x*2) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		ll cost;
		cin >> a >> b >> cost;
		
		adj[a].push_back({b, cost});
		adj[b].push_back({a, cost});
	}
	
	for(auto p : adj[1]){
		dfs(p.first, 1, p.second);
	}
	
	ll sum = 0;
	for(ll i=0;i<61;i++){
		ll one = 0, zero = 0;
		ll bit = (1ll << i);
		for(int x=1;x<=n;x++){
			if((dist[x]&bit)){
				one++;
			} else {
				zero++;
			}
		}
		
		sum += mulmod(mulmod(one,zero), bit) % mod;
		sum %= mod;
	}
	cout << sum << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

