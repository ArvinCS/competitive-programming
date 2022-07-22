#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

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
} dsuX, dsuY;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	
	ll sumA = 0, sumB = 0;
	array<int, 3> a[p], b[q];
	for(int x=0;x<p;x++){
		cin >> a[x][1] >> a[x][2] >> a[x][0];
		a[x][1]--; a[x][2]--;
		sumA += a[x][0];
	}
	for(int x=0;x<q;x++){
		cin >> b[x][1] >> b[x][2] >> b[x][0];
		b[x][1]--; b[x][2]--;
		sumB += b[x][0];
	}
	
	sort(a, a+p);
	sort(b, b+q);
	
	ll ans = 0;
	vector<array<int, 3>> v;
	for(int x=0;x<p;x++){
		v.push_back({a[x][0], 0, x});
	}
	for(int x=0;x<q;x++){
		v.push_back({b[x][0], 1, x});
	}
	
	sort(v.begin(), v.end());
	dsuX.reset(n*1ll*m);// dsuY.reset(n);
	
	// we can do mst algo like kruskal
	// notice that if we can merge planet a and b
	// we can use this edge to connect each unconnected cities between planet a and b
	// later if we want merge some cities in the same planet, we only need to merge it in the planet a or b, not both.
	// proof: because we merged all unconnected cities between planet a and b, if we merge two cities in the same planet, we can still travel these two cities in the other planet because our previous edges.
	// hence, it will reduce our cost to the optimal
	// TC: O(N + M + (P+Q)log(P+Q))
	// MC: O(N+M+P+Q)
	
	ll cnt = n*1ll*m;
	for(int x=0;x<v.size();x++){
		if(v[x][1] == 0){
			int idx = v[x][2];
			for(int y=0;y<n;y++){
				if(dsuX.merge(a[idx][1]+y*m, a[idx][2]+y*m)){
					ans += a[idx][0];
				}
			}
		} else {
			int idx = v[x][2];
			for(int y=0;y<m;y++){
				if(dsuX.merge(b[idx][1]*m+y, b[idx][2]*m+y)){
					ans += b[idx][0];
				}
			}
		}
	}
	
	cout << sumA*n+sumB*m-ans << "\n";
    return 0;
}

