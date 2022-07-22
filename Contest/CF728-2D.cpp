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

const int maxN = 205;
const int lgN = log2(maxN) + 1;

vector<int> adj[maxN];
int parrent[lgN+2][maxN], lvl[maxN], dist[maxN];
bool visited[maxN];
ll table[maxN][maxN];

ll powmod(ll x, ll y){
	ll ans = 1;
	
	while(y > 0){
		if(y&1) ans = (ans * x) % mod;
		
		y >>= 1;
		x = (x*x) % mod;
	}
	return ans;
}

void dfs(int curNode){
	visited[curNode] = true;
	
	for(int x=1;x<lgN;x++){
		parrent[x][curNode] = parrent[x-1][parrent[x-1][curNode]];
	}

	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			lvl[nxt] = lvl[curNode]+1;
			dist[nxt] = dist[curNode]+1;
			parrent[0][nxt] = curNode;
			dfs(nxt);
		}
	}
}

int findLCA(int x, int y){
	int a = x, b = y;
	if(lvl[a] > lvl[b]) swap(a, b);
	
	for(int i=lgN-1;i>=0;i--){
		if(lvl[a] <= lvl[b] - (1 << i)){
			b = parrent[i][b];
		}
	}
	
	if(a == b) return a;
	for(int i=lgN-1;i>=0;i--){
		if(parrent[i][a] != parrent[i][b]){
			a = parrent[i][a];
			b = parrent[i][b];
		}
	}
	return parrent[0][a];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	for(int x=1;x<maxN;x++){
		table[0][x] = 0;
	}
	for(int x=1;x<maxN;x++){
		table[x][0] = 1;
	}
	for(int x=1;x<maxN;x++){
		for(int y=1;y<maxN;y++){
			table[x][y] = (table[x-1][y] + table[x][y-1]) * powmod(2, mod-2) % mod;
		}
	}
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll ans = 0;
	for(int root=0;root<n;root++){
		fill(visited, visited+maxN, false);
		fill(lvl, lvl+maxN, inf_int);
		
		parrent[0][root] = root;
		dist[root] = lvl[root] = 0;
		
		dfs(root);
		
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				int lca = findLCA(x, y);
				if(lca == x) continue;
				
				int distX = dist[x] - dist[lca], distY = dist[y] - dist[lca];
				
				ans += table[distX][distY];
				ans %= mod;
			}
		}
	}
	
	cout << ans * powmod(n, mod-2) % mod << "\n";
    return 0;
}

