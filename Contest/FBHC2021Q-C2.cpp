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

const int maxN = 55;
const int logN = log2(maxN);

vector<int> adj[maxN];
int parrent[logN+1][maxN], level[maxN];
ll cnt[maxN], c[maxN], color[maxN];

void dfs(int curNode, int prvNode, int col, ll sum){
	sum += c[curNode];
	
	cnt[curNode] = sum;
	color[curNode] = col;
	
	for(int x=1;x<=logN;x++){
		parrent[x][curNode] = parrent[x-1][parrent[x-1][curNode]];
	}
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			level[nxt] = level[curNode]+1;
			parrent[0][nxt] = curNode;
			dfs(nxt, curNode, col, sum);
		}
	} 
}

int lca(int a, int b){
	if(level[a] > level[b]) swap(a, b);
	
	for(int x=logN;x>=0;x--){
		if(level[a] <= level[b] - (1 << x)){
			b = parrent[x][b];
		}
	}
	
	if(a == b) return a;
	
	for(int x=logN;x>=0;x--){
		if(parrent[x][a] != parrent[x][b]){
			a = parrent[x][a];
			b = parrent[x][b];
		}
	}
	return parrent[0][a];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("gold_mine_chapter_1_input.txt","r",stdin);
//	freopen("gold_mine_chapter_1_output.txt","w",stdout);

	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, k;
		cin >> n >> k;
		
		for(int x=0;x<n;x++){
			cin >> c[x];
		}
		
		for(int x=0;x<n;x++){
			adj[x].clear();
			cnt[x] = 0;
		}
		
		for(int x=0;x<n-1;x++){
			int a, b;
			cin >> a >> b;
			
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		for(int x=0;x<=logN;x++) parrent[x][0] = 0;
		cnt[0] = 0;
		level[0] = 0;
		
		for(int x=0;x<adj[0].size();x++){
			level[adj[0][x]] = 1;
			parrent[0][adj[0][x]] = 0;
			dfs(adj[0][x], 0, x, 0);
		}
		
		bool open[n];
		fill(open, open+n, true);
		
		ll ans = 0, endp = 0;
		for(int x=0;x<k;x++){
			ll best = 0, idx = -1;
			for(int y=1;y<n;y++){
				if(best < cnt[y]){
					best = cnt[y];
					idx = y;
				}
			}
			
			ans += best;
			if(open[idx]) endp++;
			
			ll tmp[n];
			for(int y=0;y<n;y++){
				if(lca(y, idx) != 0) open[y] = false;
				tmp[y] = (cnt[y] - cnt[lca(y, idx)]);
			}
			for(int y=0;y<n;y++) cnt[y] = tmp[y];
		}
		
		for(int x=0;x<min(n-1, k);x++){
			ll best = 0, idx = -1;
			for(int y=0;y<n;y++){
				if(best < cnt[y]){
					best = cnt[y];
					idx = y;
				}
			}
			
			ans += best;
			if(open[idx]) endp++;
			
			ll tmp[n];
			for(int y=0;y<n;y++){
				if(lca(y, idx) != 0) open[y] = false;
				tmp[y] = (cnt[y] - cnt[lca(y, idx)]);
			}
			for(int y=0;y<n;y++) cnt[y] = tmp[y];
		}
		
		ll best = 0;
		for(int y=0;y<n;y++){
			if(best < cnt[y] && (endp >= 2 || (endp == 1 && open[y]) || (y == 0 && endp == 0))){
				best = cnt[y];
			}
		}
		ans += best;
		
		for(int x=0;x<=logN;x++) parrent[x][0] = 0;
		cnt[0] = 0;
		level[0] = 0;
		
		for(int x=0;x<adj[0].size();x++){
			level[adj[0][x]] = 1;
			parrent[0][adj[0][x]] = 0;
			dfs(adj[0][x], 0, x, 0);
		}
		
		bool open[n];
		fill(open, open+n, true);
		
		for
		
		ll ans2 = 0;
		
		cout << "Case #" << i << ": " << max(ans, ans2) << "\n";
	}

    return 0;
}
