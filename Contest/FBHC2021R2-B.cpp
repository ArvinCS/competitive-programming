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

const int maxN = 8e5 + 5;
const int logN = log2(maxN);

vector<pair<int, int>> adj[maxN];
int f[maxN], edge[maxN];
int parrent[maxN][logN+1], level[maxN], pos[maxN], prv[maxN];
bool mark[maxN];

int getParrent(int x){
	if(prv[x] == x) return x;
	return prv[x] = getParrent(prv[x]);
}

int lca(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN;x>=0;x--){
		if(level[a] <= level[b]-(1<<x)){
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

void dfs(int curNode, int prvNode){
	for(int x=1;x<=logN;x++){
		parrent[curNode][x] = parrent[parrent[curNode][x-1]][x-1];
	}
	
	if(pos[f[curNode]] != -1){
		int lc = lca(pos[f[curNode]], curNode);
		
		int cur = pos[f[curNode]];
		while(cur != 0 && level[cur] > level[lc] && !mark[edge[cur]]){
			mark[edge[cur]] = true;
			prv[cur] = getParrent(lc);
			cur = getParrent(parrent[cur][0]);
		}
		
		cur = curNode;
		while(cur != 0 && level[cur] > level[lc] && !mark[edge[cur]]){
			mark[edge[cur]] = true;
			prv[cur] = getParrent(lc);
			cur = getParrent(parrent[cur][0]);
		}
		
		pos[f[curNode]] = lc;
	} else {
		pos[f[curNode]] = curNode;
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			parrent[nxt.first][0] = curNode;
			level[nxt.first] = level[curNode]+1;
			edge[nxt.first] = nxt.second;
			dfs(nxt.first, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("chainblock_input.txt","r",stdin);
	freopen("chainblock_output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			mark[x] = false;
			pos[x] = -1;
			edge[x] = -1;
			level[x] = -1;
			prv[x] = x;
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back({b, x});
			adj[b].push_back({a, x});
		}
		
		for(int x=0;x<n;x++){
			cin >> f[x];
			f[x]--;
		}
		
		parrent[0][0] = 0;
		level[0] = 0;
		dfs(0, -1);
		
		int ans = 0;
		for(int x=0;x<n-1;x++){
			if(!mark[x]){
				ans++;
			}
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

