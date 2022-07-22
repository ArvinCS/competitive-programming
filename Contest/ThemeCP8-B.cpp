#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct DSU {
	int parent[2*maxN], sz[2*maxN];
	
	void reset(){
		for(int x=0;x<2*maxN;x++){
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
	
	bool check(int x, int y){
		return getParent(x) == getParent(y);
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int f[n];
	for(int x=0;x<n;x++){
		cin >> f[x];
		f[x]--;
	}
	
	dsu.reset();
	
	vector<int> g;
	vector<int> h;
	for(int x=0;x<n;x++){
		if(dsu.getParent(f[x]) != f[x]){
			cout << "-1\n";
			return 0;
		}
		
		dsu.merge(f[x], x);
	}
	
	bool valid[n];
	fill(valid, valid+n, true);
	
	vector<int> v;
	for(int x=0;x<n;x++){
		if(dsu.getParent(x) == x){
			v.push_back(x);
		}
	}
	
	for(int x=0;x<n;x++){
		int idx = lower_bound(v.begin(), v.end(), dsu.getParent(x)) - v.begin();
		g.push_back(idx+1);
	}
	for(int x=0;x<v.size();x++){
		h.push_back(f[v[x]]+1);
	}
	
	cout << h.size() << "\n";
	for(int x=0;x<g.size();x++){
		if(x > 0) cout << " ";
		cout << g[x];
	}
	cout << "\n";
	for(int x=0;x<h.size();x++){
		if(x > 0) cout << " ";
		cout << h[x];
	}
	cout << "\n";
    return 0;
}

