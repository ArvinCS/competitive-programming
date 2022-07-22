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
const int logN = log2(maxN);

vector<int> adj[maxN];
int parrent[maxN][logN+1], level[maxN];

void dfs(int curNode, int prvNode){
	for(int x=1;x<=logN;x++){
		parrent[curNode][x] = parrent[parrent[curNode][x-1]][x-1];
	}
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			level[nxt] = level[curNode]+1;
			parrent[nxt][0] = curNode;
			dfs(nxt, curNode);
		}
	}
}

int lca(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN;x>=0;x--){
		if(level[a] <= level[b]-(1 << x)){
			b = parrent[b][x];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN;x>=0;x--){
		if(parrent[a][x] != parrent[b][x]){
			a = parrent[a][x];
			b = parrent[b][x];
		}
	}
	
	return parrent[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	int lc = -1;
	bool univ[n];
	fill(univ, univ+n, false);
	
	for(int x=0;x<2*k;x++){
		int v;
		cin >> v;
		
		v--;
		univ[v] = true;
		lc = v;
	}
	
	for(int x=0;x<n-1;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	level[0] = 0;
	parrent[0][0] = 0;
	dfs(0, 0);
	
	ll dist = 0;
	for(int x=1;x<n;x++){
		if(univ[x]){
			lc = lca(lc, x);
			dist += level[x];
		}
	}
	
	dist -= level[lc]*(2*k - (univ[0] ? 2 : 0));
	
	cout << dist << "\n";
    return 0;
}

