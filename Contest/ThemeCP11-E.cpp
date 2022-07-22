#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;
const int logN = log2(maxN)+1;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
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
} dsu;

vector<pair<int, int>> adj[maxN];
pair<int, int> parent[maxN];
int level[maxN], cnt[maxN];

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			parent[nxt.first] = {curNode, nxt.second};
			level[nxt.first] = level[curNode]+1;
			dfs(nxt.first, curNode);
		}
	}
}

pair<int, bool> dfs2(int curNode, int prvNode){
	bool remain = false;
	int ans = 0;
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			pair<int, bool> p = dfs2(nxt.first, curNode);
			
			ans += p.first;
			if(cnt[nxt.second] % 2 == 0){
				if(p.second){
					ans++;
				}
			} else {
				if(p.second){
					if(remain){
						ans++;
						remain = false;
					} else {
						remain = true;
					}
				} else {
					if(remain){
						ans++;
						remain = false;
					} else {
						remain = true;
					}
				}
			}
		}
	}
	
	return {ans, remain};
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	dsu.reset();
	
	int idx = 0;
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		if(dsu.merge(a, b)){
			adj[a].push_back({b, idx});
			adj[b].push_back({a, idx});
			idx++;
		}
	}
	
	// graph should be better if it's a tree
	// because splitting edges in paths won't contributes any success
	// how to count extra query?
	// dfs, each nodes, check every single edge that is odd 
	// add cnt/2, bring 1 remaining to parent if cnt is odd.
	
	parent[0] = {0, -1};
	level[0] = 0;
	dfs(0, 0);
	
	fill(cnt, cnt+idx, 0);
	
	int q;
	cin >> q;
	
	vector<vector<int>> ans;
	while(q--){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		vector<int> l, r;
		while(level[a] != level[b]){
			if(level[a] < level[b]){
				r.push_back(b);
				cnt[parent[b].second]++;
				b = parent[b].first;
			} else {
				l.push_back(a);
				cnt[parent[a].second]++;
				a = parent[a].first;
			}
		}
		while(a != b){
			l.push_back(a);
			cnt[parent[a].second]++;
			a = parent[a].first;
			
			r.push_back(b);
			cnt[parent[b].second]++;
			b = parent[b].first;
		}
		l.push_back(a);
		
		while(!r.empty()){
			l.push_back(r.back());
			r.pop_back();
		}
		
		ans.push_back(l);
	}
	
	bool possible = true;
	for(int x=0;x<idx;x++){
		if(cnt[x] % 2 != 0){
			possible = false;
			break;
		}
	}
	
	if(possible){
		cout << "YES\n";
		for(auto v : ans){
			cout << v.size() << "\n";
			for(int x=0;x<v.size();x++){
				if(x > 0) cout << " ";
				cout << v[x]+1;
			}
			cout << "\n";
		}
	} else {
		cout << "NO\n";
		
		pair<int, bool> p = dfs2(0, -1);
		cout << p.first+p.second << "\n";
	}
    return 0;
}

