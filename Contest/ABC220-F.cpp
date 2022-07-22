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

vector<int> adj[maxN], topo;
int sz[maxN], parrent[maxN][logN+1], level[maxN];

ll dfs(int curNode, int prvNode){
	for(int x=1;x<=logN;x++){
		parrent[curNode][x] = parrent[parrent[curNode][x-1]][x-1];
	}
	
	sz[curNode] = 1;
	
	ll ans = 0;
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parrent[nxt][0] = curNode;
			level[nxt] = level[curNode]+1;
			
			ans += dfs(nxt, curNode)+sz[nxt];
			sz[curNode] += sz[nxt];
		}
	}
	topo.push_back(curNode);
	return ans;
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
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
	ll dist = dfs(0, 0);
	ll ans[n];
	ans[0] = dist;
	reverse(topo.begin(), topo.end());
	
	vector<int> v;
	int curNode = 0;
	for(int i=1;i<topo.size();i++){
		int top = lca(curNode, topo[i]);
		
		while(curNode != top){
			dist += sz[curNode];
			dist -= n-sz[curNode];
			curNode = parrent[curNode][0];
		}
		
		curNode = topo[i];
		while(curNode != top){
			v.push_back(curNode);
			curNode = parrent[curNode][0];
		}
		
		curNode = top;
		while(!v.empty()){
			dist -= sz[v.back()];
			dist += n-sz[v.back()];
			curNode = v.back();
			v.pop_back();
		}
		
		curNode = topo[i];
		ans[topo[i]] = dist;
	}
	
	for(int x=0;x<n;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

