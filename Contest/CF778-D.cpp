#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;
const int maxN = 2e5 + 5;

ll prime[maxN];
vector<pair<int, int>> adj[maxN];
ll a[maxN];
array<ll, 4> f[maxN];
map<ll, ll> mp, mx;

ll powmod(ll x, ll y){
	ll ans = 1;
	
	x %= mod;
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}

void add(ll val, int cnt){
	while(val > 1){
		ll div = prime[val];
		
		mp[div] += cnt;
		mx[div] = max(mx[div], mp[div]);
		
		val /= div;
	}	
}

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(a[nxt.first] == -1){
			if(f[nxt.second][0] == curNode){
				a[nxt.first] = (a[curNode] * f[nxt.second][3] % mod) * powmod(f[nxt.second][2], mod-2) % mod;
				
				add(f[nxt.second][2], 1);
				add(f[nxt.second][3], -1);
				dfs(nxt.first, curNode);
				
				add(f[nxt.second][2], -1);
				add(f[nxt.second][3], 1);
			} else {
				a[nxt.first] = (f[nxt.second][2] * a[curNode] % mod) * powmod(f[nxt.second][3], mod-2) % mod;
				
				add(f[nxt.second][3], 1);
				add(f[nxt.second][2], -1);
				
				dfs(nxt.first, curNode);
				
				add(f[nxt.second][3], -1);
				add(f[nxt.second][2], 1);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(int x=0;x<maxN;x++){
		prime[x] = x;
	}
	for(int x=2;x*x<maxN;x++){
		if(prime[x] == x){
			for(int y=2*x;y<maxN;y+=x){
				if(prime[y] == y) prime[y] = x;
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		for(int x=0;x<=n;x++){
			adj[x].clear();
			a[x] = -1;
		}
		
		for(int x=0;x<n-1;x++){
			cin >> f[x][0] >> f[x][1] >> f[x][2] >> f[x][3];
			
			f[x][0]--; f[x][1]--;
			
			ll gcd = __gcd(f[x][2], f[x][3]);
			
			f[x][2] /= gcd;
			f[x][3] /= gcd;
			
			adj[f[x][0]].push_back({f[x][1], x});
			adj[f[x][1]].push_back({f[x][0], x});
		}
		
		mp.clear(); mx.clear();
		
		a[0] = 1;
		dfs(0, 0);
		
		ll mul = 1;
		
		for(auto p : mx){
			for(int x=0;x<p.second;x++){
				mul *= p.first;
				mul %= mod;
			}
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			ans += a[x];
			ans %= mod;
		}
		
		cout << (ans*mul % mod) << "\n";
	}
	
    return 0;
}

