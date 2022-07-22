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

ll table[maxN];

void dfs(vector<ll> adj[maxN], ll curNode, ll prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(adj, nxt, curNode);
			
			table[curNode] += table[nxt];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n;
		
		vector<pair<ll, ll>> edges;
		vector<ll> adj[n+5];
		for(int x=0;x<n-1;x++){
			ll a, b;
			cin >> a >> b;

			edges.push_back({a, b});
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		fill(table, table+n+5, 1);
		
		dfs(adj, 1ll, 0ll);
		
		vector<ll> best;
		for(int x=0;x<n-1;x++){
			ll a = table[edges[x].first], b = table[edges[x].second];
			if(a > b){
				a = n-b;
			} else {
				b = n-a;
			}
			
			best.push_back(a*b);
		}
		
		sort(best.begin(), best.end());
		
		cin >> m;
		
		vector<ll> data;
		for(int x=0;x<m;x++){
			ll tmp;
			cin >> tmp;
			
			data.push_back(tmp);
		}
		
		for(int x=m;x<n-1;x++) data.push_back(1);
		
		sort(data.begin(), data.end());
		
		if(m > n-1){
			ll last = 1;
			while(data.size() >= n-1){
				last = (last * data.back()) % mod;
				data.pop_back();
			}
			data.push_back(last);
		}
				
		ll ans = 0;
		for(int x=0;x<n-1;x++){
			ans += (best[x] % mod * data[x] % mod) % mod;
			ans %= mod;
		}
		
		cout << ans % mod << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

