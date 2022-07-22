#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 6e5;

struct DSU {
	pair<int, int> parent[maxN];
	int sz[maxN];
	bool bipartite[maxN];
	stack<array<int, 7>> st;
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parent[x] = {x, 1};
			sz[x] = 1;
			bipartite[x] = true;
		}
	}
	
	void undo(int x){
		while(st.size() > x){
			int a = st.top()[0], b = st.top()[1], szA = st.top()[2], szB = st.top()[3], bipA = st.top()[4], bipB = st.top()[5], prvB = st.top()[6];
			st.pop();
			
			if(b != -1){
				parent[b] = {b, 1};
				sz[b] = szB;
				bipartite[b] = bipB;
			}
			if(a != -1){
				bipartite[a] = bipA;
				sz[a] = szA;
			}
		}
	}
	
	pair<int, int> getParent(int x){
		if(parent[x].first != x){
			int par = parent[x].second;
			pair<int, int> p = getParent(parent[x].first);
			p.second += par;
			p.second %= 2;
			return p;
		}
		
		return parent[x];
	}
	
	bool merge(int x, int y){
		pair<int, int> a = getParent(x);
		pair<int, int> b = getParent(y);
		
		if(sz[a.first] < sz[b.first]) swap(a, b);
		if(a.first == b.first){
			st.push({a.first, -1, sz[a.first], -1, bipartite[a.first], -1, -1});
			
			if(a.second % 2 == b.second % 2){
				bipartite[a.first] = false;
			}
		} else {
			st.push({a.first, b.first, sz[a.first], sz[b.first], bipartite[a.first], bipartite[b.first], b.second});
			parent[b.first] = {a.first, (a.second+b.second+1)%2};
			bipartite[a.first] &= bipartite[b.first];
			sz[a.first] += sz[b.first];
		}
		return bipartite[a.first];
	}
	
	int ver(){
		return st.size();
	}
};

DSU dsu;
vector<array<int, 3>> adj[maxN];
vector<pair<int, int>> self[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
		c[x]--;
	}
	
	vector<pair<int, int>> v;
	
	ll ans = k*1ll*(k-1)/2;
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		if(c[a] == c[b]){
			self[c[a]].push_back({a, b});
			continue;
		}
		
		if(c[a] > c[b]) swap(a, b);
		
		v.push_back({c[a], c[b]});
		adj[c[a]].push_back({c[b], a, b});
	}
	
	bool valid[k];
	fill(valid, valid+k, true);
	
	dsu.reset();
	
	int cnt = 0;
	for(int x=0;x<k;x++){
		bool bipartite = true;
		for(auto edge : self[x]){
			bipartite &= dsu.merge(edge.first, edge.second);
		}
		
		if(!bipartite){
			ans -= k-1-cnt;
			cnt++;
			valid[x] = false;
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	vector<int> w[k];
	for(auto p : v){
		if(p.first != p.second && valid[p.first] && valid[p.second]) w[p.first].push_back(p.second);	
	}
	
	int cp = dsu.ver();
	for(int x=0;x<k;x++){		
		sort(adj[x].begin(), adj[x].end());
		
		int pos = 0;
		for(auto y : w[x]){
			bool bipartite = true;
			
			while(pos < adj[x].size() && adj[x][pos][0] < y) pos++;
			while(pos < adj[x].size() && adj[x][pos][0] == y){
				bipartite &= dsu.merge(adj[x][pos][1], adj[x][pos][2]);
				pos++;
			}
			
			if(!bipartite){
				ans--;
			}
			
			dsu.undo(cp);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

