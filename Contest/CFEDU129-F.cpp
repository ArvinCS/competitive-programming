#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;
const int logN = log2(maxN)+1;

vector<pair<int, int>> adj[maxN];
vector<pair<int, int>> v[4*maxN];
vector<pair<int, int>> w[maxN];
ll ans[maxN];

struct DSU {
	int parent[maxN], sz[maxN];
	stack<pair<int, int>> st;
	
	void reset(int n){
		for(int x=0;x<n;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return getParent(parent[x]);
	}
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			st.push({b, sz[b]});
		}
	}
	
	void rollback(){
		assert(!st.empty());
		
		sz[parent[st.top().first]] -= st.top().second;
		parent[st.top().first] = st.top().first;
		st.pop();
	}
} dsu;

void solve(int idx, int l, int r){
	if(l > r) return;
	for(int x=0;x<v[idx].size();x++){
		dsu.merge(v[idx][x].first, v[idx][x].second);
	}
	if(l == r){
		for(auto p : w[l]){
			ans[l] += dsu.sz[dsu.getParent(p.first)] * 1ll * dsu.sz[dsu.getParent(p.second)];
		}
	} else {
		int m = (l+r) >> 1;
		solve(2*idx+1, l, m);
		solve(2*idx+2, m+1, r);
	}
	
	for(int x=0;x<v[idx].size();x++){
		dsu.rollback();
	}
}

void add(int idx, int curL, int curR, int l, int r, int p, int q){
	if(curL > curR || l > r) return;
	if(l <= curL && curR <= r){
		v[idx].push_back({p, q});
		return;
	}
	
	int curM = (curL+curR) >> 1;
	
	add(2*idx+1, curL, curM, l, min(curM, r), p, q);
	add(2*idx+2, curM+1, curR, max(l, curM+1), r, p, q);
}
	
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n-1;x++){
		int u, v, val;
		cin >> u >> v >> val;
		
		w[val].push_back({u-1, v-1});
	}
	
	dsu.reset(n);
	
	fill(ans, ans+n+1, 0);
	
	for(int x=1;x<=n;x++){
		for(auto p : w[x]){
			add(0, 1, n, 1, x-1, p.first, p.second);
			add(0, 1, n, x+1, n, p.first, p.second);
		}
	}
	
	solve(0, 1, n);
	
	ll sum = 0;
	for(int x=1;x<=n;x++){
		sum += ans[x];
	}
	
	cout << sum << "\n";
    return 0;
}

