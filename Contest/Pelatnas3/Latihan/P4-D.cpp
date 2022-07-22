#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 * 4;
const ll inf = 1e18;

int tree[4*maxN];

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	// just ordinary line sweep
	// observation 1: build edge only between adjacent point with the same x or y
	// observation 2: minimum cost means minimize the cost to connect each computer and num of components
	// observation 3: it is worth to connect all computers with cost <= K
	// observation 4: if the num of components still not less or equal to P, keep connecting edges although the cost might be > K
	// it is impossible to connect all computers iff the num of components at the end is > P.
	
	int n;
	cin >> n;
	
	vector<int> vX, vY;
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		vX.push_back(p[x].first);
		vY.push_back(p[x].second);
	}
	
	int m;
	cin >> m;
	
	array<int, 4> b[m];
	for(int x=0;x<m;x++){
		cin >> b[x][0] >> b[x][1] >> b[x][2] >> b[x][3];
		vX.push_back(b[x][0]);
		vY.push_back(b[x][1]);
		vX.push_back(b[x][2]);
		vY.push_back(b[x][3]);
	}
	
	sort(vX.begin(), vX.end());
	vX.erase(unique(vX.begin(), vX.end()), vX.end());
	
	sort(vY.begin(), vY.end());
	vY.erase(unique(vY.begin(), vY.end()), vY.end());
	
	for(int x=0;x<n;x++){
		p[x].first = lower_bound(vX.begin(), vX.end(), p[x].first) - vX.begin();
		p[x].second = lower_bound(vY.begin(), vY.end(), p[x].second) - vY.begin();
	}
	for(int x=0;x<m;x++){
		for(int y=0;y<4;y++){
			if(y&1){
				b[x][y] = lower_bound(vY.begin(), vY.end(), b[x][y]) - vY.begin();
			} else {
				b[x][y] = lower_bound(vX.begin(), vX.end(), b[x][y]) - vX.begin();
			}
		}
	}
	
	fill(tree, tree+4*maxN, -1e9);
	auto update = [&](auto self, int v, int curL, int curR, int l, int r, int val) -> void {
		if(l > r) return;
		if(curL == l && curR == r){
			tree[v] = val;
			return;
		}
		
		if(tree[v] != -1e9){
			tree[2*v+1] = tree[2*v+2] = tree[v];
			tree[v] = -1e9;
		}
		
		int curM = (curL+curR) >> 1;
		
		self(self, 2*v+1, curL, curM, l, min(curM, r), val);
		self(self, 2*v+2, curM+1, curR, max(l, curM+1), r, val);
	};
	
	auto query = [&](auto self, int v, int curL, int curR, int pos) -> int {
		if(curL > curR) return -1e9;
		if(curL == curR){
			return tree[v];
		}
		
		if(tree[v] != -1e9){
			tree[2*v+1] = tree[2*v+2] = tree[v];
			tree[v] = -1e9;
		}
		
		int curM = (curL+curR) >> 1;
		if(pos <= curM){
			return self(self, 2*v+1, curL, curM, pos);
		} else {
			return self(self, 2*v+2, curM+1, curR, pos);
		}
	};
	
	// for X
	vector<array<int, 3>> v;
	for(int x=0;x<n;x++){
		v.push_back({p[x].first, 0, x});
	}
	for(int x=0;x<m;x++){
		v.push_back({b[x][0], 1, x});
		v.push_back({b[x][2], 1, x});
	}
	
	sort(v.begin(), v.end());
	
	vector<array<int, 3>> edge;
	for(auto a : v){
		if(a[1] == 0){
			int prv = query(query, 0, 0, vY.size()-1, p[a[2]].second);
			if(prv >= 0){
				edge.push_back({vX[p[a[2]].first]-vX[p[prv].first], prv, a[2]});
			}
			
			update(update, 0, 0, vY.size()-1, p[a[2]].second, p[a[2]].second, a[2]);
		} else {
			int l = b[a[2]][1], r = b[a[2]][3];
			update(update, 0, 0, vY.size()-1, l, r, -1);
		}
	}
	
	// for Y
	fill(tree, tree+4*maxN, -1e9);
	v.clear();
	for(int x=0;x<n;x++){
		v.push_back({p[x].second, 0, x});
	}
	for(int x=0;x<m;x++){
		v.push_back({b[x][1], 1, x});
		v.push_back({b[x][3], 1, x});
	}
	
	sort(v.begin(), v.end());
	
	for(auto a : v){
		if(a[1] == 0){
			int prv = query(query, 0, 0, vX.size()-1, p[a[2]].first);
			if(prv >= 0){
				edge.push_back({vY[p[a[2]].second]-vY[p[prv].second], prv, a[2]});
			}
			
			update(update, 0, 0, vX.size()-1, p[a[2]].first, p[a[2]].first, a[2]);
		} else {
			int l = b[a[2]][0], r = b[a[2]][2];
			update(update, 0, 0, vX.size()-1, l, r, -1);
		}
	}
	
	// for set of msts
	dsu.reset(n);
	sort(edge.begin(), edge.end());
	
	int comp = n;
	ll cur = 0;
	vector<pair<int, ll>> cost;
	for(int x=0;x<edge.size();x++){
//		cout << edge[x][1] << "-" << edge[x][2] << " = " << edge[x][0] << "\n";
		if(dsu.merge(edge[x][1], edge[x][2])){
			cur += edge[x][0];
			comp--;
		}
		cost.push_back({comp, cur});
		
//		cout << comp << " - " << cur << "\n";
	}
	
	int q;
	cin >> q;
	
	while(q--){
		int p;
		cin >> p;
		
		ll k;
		cin >> k;
		
		ll ans = (p == n ? n*k : inf);
		// optimal cost is max(idx such cost of idx-th edge is K, idx such num of comps of first idx edges is P)
		int idx1 = edge.size(), idx2 = edge.size();
		int left = 0, right = edge.size()-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(edge[mid][0] > k){
				idx1 = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		left = 0, right = cost.size()-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(cost[mid].first <= p){
				idx2 = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		int idx = max(idx1-1, idx2);
		if(idx >= 0 && idx2 < cost.size()){
			ans = min(ans, cost[idx].first*k+cost[idx].second);
		}
		
		cout << (ans != inf ? ans : -1) << "\n";
	}
    return 0;
}

