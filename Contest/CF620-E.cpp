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

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;

int n, level[maxN], parrent[maxN][logN];
vector<int> adj[maxN];

void dfs(int curNode, int prvNode){
	for(int x=1;x<logN;x++){
		parrent[curNode][x] = parrent[parrent[curNode][x-1]][x-1];
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parrent[nxt][0] = curNode;
			level[nxt] = level[curNode]+1;
			
			dfs(nxt, curNode);
		}
	}
}

int findLCA(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN-1;x>=0;x--){
		if(level[a] <= level[b] - (1 << x)){
			b = parrent[b][x];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN-1;x>=0;x--){
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

	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	parrent[0][0] = 0;
	level[0] = 0;
	
	dfs(0, 0);
	
	int q;
	cin >> q;
	
	while(q--){
		int u, v, a, b, k;
		cin >> u >> v >> a >> b >> k;
		
		u--; v--; a--; b--;
		int lca = findLCA(a, b);
		
		int dist[3];
		dist[0] = level[a]+level[b]-2*level[lca];
		
		for(int i=1;i<=2;i++){
			int tmp = level[a]+level[u]-2*level[findLCA(a, u)];
			tmp += level[b]+level[v]-2*level[findLCA(b, v)];
			tmp++;
			
			dist[i] = tmp;
			swap(u, v);
		}
				
		bool found = false;
		for(int i=0;i<3;i++){
			if(k >= dist[i] && (k-dist[i]) % 2 == 0){
				found = true;
			}
		}
		
		if(found){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
    return 0;
}

