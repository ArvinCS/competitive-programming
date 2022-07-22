#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct DSU {
	int parent[maxN], mx[maxN], sz[maxN];
	
	void reset(int n, int a[]){
		for(int x=0;x<n;x++){
			parent[x] = x;
			sz[x] = 1;
			mx[x] = a[x];
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			mx[a] = max(mx[a], mx[b]);
		}
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	vector<tuple<int, int, int>> edge;
	for(int x=0;x<n-1;x++){
		int u, v;
		cin >> u >> v;
		
		u--; v--;
		edge.push_back(make_tuple(max(a[u], a[v]), u, v));
	}
	
	sort(edge.begin(), edge.end());
	dsu.reset(n, a);
	
	ll ans = 0;
	for(int x=0;x<edge.size();x++){
		int u = get<1>(edge[x]), v = get<2>(edge[x]);
		
		ans += dsu.mx[dsu.getParent(u)]+dsu.mx[dsu.getParent(v)];
		dsu.merge(u, v);
	}
	
	cout << ans << "\n";
    return 0;
}

