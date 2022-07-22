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

const int maxN = 2e5 + 50;
const int lgN = log2(maxN)+1;

int parrent[lgN+2][maxN], lvl[maxN], cnt[maxN], n, k;
bool valid[maxN];
vector<int> adj[maxN], topo;

int dfs(int curNode, int prvNode){
	for(int x=1;x<=lgN;x++){
		parrent[x][curNode] = parrent[x-1][parrent[x-1][curNode]];
	}
	
	cnt[curNode] = 0;	
	int ans = 0;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			parrent[0][nxt] = curNode;
			lvl[nxt] = lvl[curNode]+1;
			ans += dfs(nxt, curNode);
			
			cnt[curNode] += valid[nxt];
		}
	}
	ans += cnt[curNode]/k;
	
	if(cnt[curNode] == adj[curNode].size()-(curNode != prvNode) && cnt[curNode] % k == 0) valid[curNode] = true;
	else valid[curNode] = false;
	
	topo.push_back(curNode);
	return ans;
}

int lca(int x, int y){
	if(lvl[x] > lvl[y]) swap(x, y);
	
	for(int i=lgN;i>=0;i--){
		if(lvl[x] <= lvl[y]-(1 << i)){
			y = parrent[i][y];
		}
	}
	
	if(x == y) return x;
	
	for(int i=lgN;i>=0;i--){
		if(parrent[i][x] != parrent[i][y]){
			x = parrent[i][x];
			y = parrent[i][y];
		}
	}
	return parrent[0][x];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		cin >> n >> k;
		
		topo.clear();
		for(int x=0;x<n;x++){
			adj[x].clear();
		}
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		lvl[0] = 0;
		parrent[0][0] = 0;
		int cur = dfs(0, 0);
		int ans = cur;
		
		reverse(topo.begin(), topo.end());
		
		int curNode = 0;
		for(int x=1;x<topo.size();x++){
			int lcaNode = lca(curNode, topo[x]);
			
			while(curNode != lcaNode){
				cur -= cnt[curNode]/k;
				cur -= cnt[parrent[0][curNode]]/k;
				
				cnt[curNode] -= valid[parrent[0][curNode]];
				
				if(cnt[curNode] == adj[curNode].size()-1 && cnt[curNode] % k == 0) valid[curNode] = true;
				else valid[curNode] = false;
				
				cnt[parrent[0][curNode]] += valid[curNode];
				
				if(cnt[parrent[0][curNode]] == adj[parrent[0][curNode]].size() && cnt[parrent[0][curNode]] % k == 0) valid[parrent[0][curNode]] = true;
				else valid[parrent[0][curNode]] = false;
				
				cur += cnt[curNode]/k;
				cur += cnt[parrent[0][curNode]]/k;
				
				curNode = parrent[0][curNode];
			}
			
			vector<int> w;
			int tmp = topo[x];
			while(tmp != lcaNode){
				w.push_back(tmp);
				tmp = parrent[0][tmp];
			}
			
			for(int y=w.size()-1;y>=0;y--){
				cur -= cnt[curNode]/k;
				cur -= cnt[w[y]]/k;
				
				cnt[curNode] -= valid[w[y]];
				
				if(cnt[curNode] == adj[curNode].size()-1 && cnt[curNode] % k == 0) valid[curNode] = true;
				else valid[curNode] = false;
				
				cnt[w[y]] += valid[curNode];
				
				if(cnt[w[y]] == adj[w[y]].size() && cnt[w[y]] % k == 0) valid[w[y]] = true;
				else valid[w[y]] = false;
				
				cur += cnt[curNode]/k;
				cur += cnt[w[y]]/k;	
				
				curNode = w[y];
			}
			
//			cout << topo[x-1] << " " << topo[x] << " -> " << cur << "\n";
			ans = max(ans, cur);
		}
		
		cout << ans << "\n";
	}

    return 0;
}

