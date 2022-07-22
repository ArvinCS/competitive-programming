#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 55;

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
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
} dsu;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<ll, int>> v;
	int l[m], r[m];
	ll w[m];
	for(int x=0;x<m;x++){
		cin >> l[x] >> r[x] >> w[x];
		v.push_back({w[x], x});
	}
	
	vector<pair<ll, int>> a, b;
	for(int x=0;x<n-1;x++){
		int idx;
		cin >> idx;
		
		idx--;
		a.push_back({w[idx], idx});
	}
	
	for(int x=0;x<n-1;x++){
		int idx;
		cin >> idx;
		
		idx--;
		b.push_back({w[idx], idx});
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(v.begin(), v.end());
	
	vector<ll> mn, mx;
	
	dsu.reset(n);
	for(int x=0;x<v.size();x++){
		if(dsu.getParent(l[v[x].second]) != dsu.getParent(r[v[x].second])){
			dsu.merge(l[v[x].second], r[v[x].second]);
			mn.push_back(v[x].first);
		}
	}
	
	sort(v.rbegin(), v.rend());
	
	dsu.reset(n);
	for(int x=0;x<v.size();x++){
		if(dsu.getParent(l[v[x].second]) != dsu.getParent(r[v[x].second])){
			dsu.merge(l[v[x].second], r[v[x].second]);
			mx.push_back(v[x].first);
		}
	}
	
	sort(mn.begin(), mn.end());
	sort(mx.begin(), mx.end());
	
	cout << max(max(mx.back()-b.back().first, mx.front()-b.front().first), max(a.back().first-mn.back(), a.front().first-mn.front())) << "\n";
	return 0;
}
