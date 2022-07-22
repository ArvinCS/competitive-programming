#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;
const int maxM = 5e5 + 5;
const int logN = log2(maxN) + 2;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(int n){
		for(int x=0;x<n;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	bool merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			return true;
		}
		return false;
	}
};

DSU dsu;
vector<pair<int, int>> adj[maxN];
pair<int, int> parent[logN][maxN];
pair<int, int> p[maxM], c[maxM];
int t[maxM], level[maxN];

void dfs(int curNode, int prvNode){
	for(int x=1;x<logN;x++){
		parent[x][curNode] = {parent[x-1][parent[x-1][curNode].first].first, max(parent[x-1][curNode].second, parent[x-1][parent[x-1][curNode].first].second)};
	}
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			level[nxt.first] = level[curNode]+1;
			if(t[c[nxt.second].second]){
				parent[0][nxt.first] = {curNode, c[nxt.second].first};
			} else {
				parent[0][nxt.first] = {curNode, -1e7};
			}
			
			dfs(nxt.first, curNode);
		}		
	}
}

pair<int, int> getLCA(int x, int y){
	if(level[x] > level[y]) swap(x, y);
	
	int mx = -1e7;
	for(int i=logN-1;i>=0;i--){
		if(level[x] <= level[y]-(1 << i)){
			mx = max(mx, parent[i][y].second);
			y = parent[i][y].first;
		}
	}
	
	if(x == y) return {x, mx};
	
	for(int i=logN-1;i>=0;i--){
		if(parent[i][x] != parent[i][y]){
			mx = max(mx, parent[i][x].second);
			mx = max(mx, parent[i][y].second);
			x = parent[i][x].first;
			y = parent[i][y].first;
		}
	}
	
	mx = max(mx, parent[0][x].second);
	mx = max(mx, parent[0][y].second);
	
	return {parent[0][x].first, mx};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	
	bool sp[n];
	fill(sp, sp+n, false);
	
	for(int x=0;x<k;x++){
		int node;
		cin >> node;
		
		sp[node-1] = true;
	}
	
	int comp = n, cnt = 0;
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second >> c[x].first;
		p[x].first--; p[x].second--; c[x].second = x;
		t[x] = (sp[p[x].first] == sp[p[x].second]);
	}
	
	sort(c, c+m);
	dsu.reset(n);
	
	ll ans = 0;
	for(int x=0;x<m;x++){
		int idx = c[x].second;
		int a = p[idx].first, b = p[idx].second;
		
		if(sp[a] != sp[b]){
			continue;
		}
		
		if(!dsu.merge(a, b)) continue;
		
		ans += c[x].first;
		comp--;

		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	for(int x=0;x<m;x++){
		int idx = c[x].second;
		int a = p[idx].first, b = p[idx].second;
		
		if(dsu.getParent(a) != dsu.getParent(b) && sp[a] != sp[b]){
			if(cnt == w){
				continue;
			} else {
				cnt++;
			}
		} else {
			continue;
		}
		
		if(!dsu.merge(a, b)) continue;
		
		ans += c[x].first;
		comp--;

		adj[a].push_back({b, x});
		adj[b].push_back({a, x});
	}
	
	level[0] = 0;
	parent[0][0] = {0, -1e7};
	
	dfs(0, 0);
		
	vector<ll> v;
	for(int x=0;x<m;x++){
		int idx = c[x].second;
		int a = p[idx].first, b = p[idx].second;
		
		if(sp[a] != sp[b]){
			pair<int, int> lca = getLCA(a, b);
			cout << a << " " << b << " " << c[x].first << " - " << lca.second << "\n";
			cout << dsu.getParent(a) << "," << dsu.getParent(b) << "\n";
			if(lca.second >= 0){
				v.push_back(c[x].first-lca.second);
			} else if(dsu.getParent(a) != dsu.getParent(b)){
				v.push_back(c[x].first);
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	int need = w-cnt;
	for(int x=0;x<min((int) v.size(), need);x++){
		cnt++;
		ans += v[x];
	}
	
	if(cnt != w || comp != 1){
		cout << "-1\n";
		return 0;
	}
	
	cout << ans << "\n";
    return 0;
}

