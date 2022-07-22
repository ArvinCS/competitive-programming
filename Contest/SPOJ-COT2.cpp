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
const int lgN = log2(maxN)+1;

bool path[maxN];
int a[maxN];
int in[maxN], out[maxN], id[maxN*2], dp[lgN+1][maxN], lvl[maxN], freq[maxN], ans[maxN], block, cnt = 0, cur = 0;
vector<int> adj[maxN];

struct Query {
	int left, right, idx, lca;
	
	bool operator < (const Query& b){
		if(left/block == b.left/block){
			return right < b.right;
		}
		return left/block < b.left/block;
	}
};

void dfs(int curNode, int prvNode){
	id[cnt] = curNode;
	in[curNode] = cnt++;
	
	for(int x=1;x<=lgN;x++){
		dp[x][curNode] = dp[x-1][dp[x-1][curNode]];
	}
	for(auto nxt : adj[curNode]){
		if(nxt == prvNode) continue;
		
		dp[0][nxt] = curNode;
		lvl[nxt] = lvl[curNode]+1;
		dfs(nxt, curNode);
	}
	
	id[cnt] = curNode;
	out[curNode] = cnt++;
}

int lca(int a, int b){
	if(lvl[a] > lvl[b]) swap(a, b);
	
	for(int x=lgN;x>=0;x--){
		if(lvl[a] <= lvl[b] - (1 << x)) b = dp[x][b];
	}
	if(a == b) return a;
	for(int x=lgN;x>=0;x--){
		if(dp[x][a] != dp[x][b]){
			a = dp[x][a];
			b = dp[x][b];
		}
	}
	return dp[0][a];
}

void check(int curNode){
	int num = a[curNode];
	if(path[curNode]){
		path[curNode] = false;
		
		freq[num]--;
		if(freq[num] == 0) cur--;
	} else {
		path[curNode] = true;
		
		if(freq[num] == 0) cur++;
		freq[num]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	
	while(cin >> n >> m){		
		int idx = 0;
		cnt = 0; cur = 0;
		fill(path, path+n, false);
		fill(freq, freq+n, 0);
		fill(dp[0], dp[lgN+1], 0);
		fill(lvl, lvl+n, 0);
		
		map<int, int> mp;
		set<int> st;
		for(int x=0;x<n;x++){
			cin >> a[x];
			st.insert(a[x]);
		}
		for(auto e : st){
			mp[e] = idx++;
		}
		for(int x=0;x<n;x++){
			adj[x].clear();
			a[x] = mp[a[x]];
		}
		
		for(int x=0;x<n-1;x++){
			int v, w;
			cin >> v >> w;
			
			v--; w--;
			adj[v].push_back(w);
			adj[w].push_back(v);
		}
		
		dfs(0, -1);
		block = sqrt(cnt);
		
		Query q[m];
		for(int x=0;x<m;x++){
			cin >> q[x].left >> q[x].right;
			
			q[x].left--; q[x].right--;
			
			if(lvl[q[x].left] > lvl[q[x].right]) swap(q[x].left, q[x].right);
			
			int tmp = lca(q[x].left, q[x].right);
			if(tmp == q[x].left){
				q[x].left = in[q[x].left];
			} else {
				q[x].left = out[q[x].left];
			}
			q[x].right = in[q[x].right];
			q[x].lca = in[tmp];
			q[x].idx = x;
		}
		
		sort(q, q+m);
		
		int left = q[0].left, right = q[0].left-1;
		for(int x=0;x<m;x++){ // [left, right]
			// Left
			while(left > q[x].left){
				left--;
				
				check(id[left]);
			}
			while(left < q[x].left){
				check(id[left]);
				
				left++;
			}
			
			// Right
			while(right < q[x].right){
				right++;
				
				check(id[right]);
			}
			while(right > q[x].right){			
				check(id[right]);
				
				right--;
			}
			
			bool special = !path[id[q[x].lca]];
			if(special){ // special case
				check(id[q[x].lca]);
			}
			ans[q[x].idx] = cur;
			
			if(special){ // special case
				check(id[q[x].lca]);
			}
		}
		
		for(int x=0;x<m;x++){
			cout << ans[x] << "\n";
		}
	}
    return 0;
}

