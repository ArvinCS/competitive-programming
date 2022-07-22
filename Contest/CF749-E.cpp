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

const int maxN = 3e5 + 5;
const int logN = log2(maxN)+1;

vector<int> adj[maxN];
vector<pair<int, int>> adj2[maxN];
bool visited[maxN];
int cnt[maxN], idx = 0;
int edge[maxN];
int a, b;
pair<int, int> prv[maxN];
vector<vector<int>> v;

void dfs(int curNode){
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt]){
			adj2[curNode].push_back({nxt, idx});
			adj2[nxt].push_back({curNode, idx});
			idx++;
			
			dfs(nxt);
		}
	}
}

void dfs2(int curNode, int prvNode){
	for(auto nxt : adj2[curNode]){
		if(nxt.first != prvNode){
			edge[nxt.first] = nxt.second;
			dfs2(nxt.first, curNode);
		}
	}
}

void dfs4(int curNode, int prvNode){
	if(curNode == b){
		int node = b;
		vector<int> w;
		while(node != a){
			w.push_back(node);
			cnt[prv[node].second]++;
			node = prv[node].first;
		}
		w.push_back(a);
		
		reverse(w.begin(), w.end());
		
		v.push_back(w);
		return;
	}
	
	for(auto nxt : adj2[curNode]){
		if(nxt.first != prvNode){
			prv[nxt.first] = {curNode, nxt.second};
			dfs4(nxt.first, curNode);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	fill(visited, visited+n, false);
	idx = 0;
	
	dfs(0);
	
	int root = -1;
	for(int x=0;x<n;x++){
		if(adj2[x].size() == 1){
			root = x;
			break;
		}
	}
	
	dfs2(root, root);
	
	fill(cnt, cnt+idx, 0);
	
	int q;
	cin >> q;
	
	while(q--){
		cin >> a >> b;
		
		a--; b--;
		
		dfs4(a, a);
	}
	
	bool valid = true;
	for(int x=0;x<idx;x++){
		if(cnt[x] % 2 != 0){
			valid = false;
			break;
		}
	}
	
	if(valid){
		cout << "YES\n";
		for(auto w : v){
			cout << w.size() << "\n";
			for(int x=0;x<w.size();x++){
				if(x > 0) cout << " ";
				cout << w[x]+1;
			}
			cout << "\n";
		}
	} else {
		cout << "NO\n";
		
		int ans = 0;
		for(int x=0;x<n;x++){
			int odd = 0;
			for(auto nxt : adj2[x]){
				if(cnt[nxt.second] % 2 != 0){
					odd++;
				}
			}
			if(odd % 2 != 0) ans++;
		}
		cout << ans/2 << "\n";
	}
    return 0;
}

