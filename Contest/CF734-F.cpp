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

const int maxN = 105;

vector<int> adj[maxN];
int depth[maxN], part[maxN];

void dfs(int curNode, int prvNode, int id){
	part[curNode] = id;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			depth[nxt] = depth[curNode]+1;
			dfs(nxt, curNode, id);
		}
	}
}

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y>0){
		if(y&1) ans = (ans*x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		
		for(int x=0;x<n;x++) adj[x].clear();
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		if(k == 2){
			cout << n * (n-1) % mod * powmod(2, mod-2) % mod << "\n";
			continue;
		}
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			if(adj[x].size() < k) continue;
			
			depth[x] = 0;
			int id = 0;
			for(auto nxt : adj[x]){
				depth[nxt] = 1;
				dfs(nxt, x, id++);
			}
			
			map<int, int> mp[n];
			int cnt[n];
			fill(cnt, cnt+n, 0);
			
			for(int y=0;y<n;y++){
				mp[depth[y]][part[y]]++;
				cnt[depth[y]]++;
			}
			
			for(int y=0;y<n;y++){
				if(cnt[y] >= k){
					ll table[k][n];	
					for(int z=0;z<n;z++) table[0][z] = 0;				
					for(auto m : mp[y]){
						table[0][m.first] = m.second;
					}
					
					for(int a=1;a<k;a++){
						ll sum = 0;
						for(int b=0;b<n;b++){
							if(b >= a){
								table[a][b] = sum*table[0][b] % mod;
							} else {
								table[a][b] = 0;
							}
							sum += table[a-1][b];
							sum %= mod;
						}
					}
					
					for(int a=0;a<n;a++){
						ans += table[k-1][a];
						ans %= mod;
					}
				}
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

