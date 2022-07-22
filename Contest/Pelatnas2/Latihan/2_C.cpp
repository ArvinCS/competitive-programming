#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

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
};

struct Vertex {
	Vertex *parent;
	Vertex *child[2];
	int idx, cnt;
	
	Vertex() : cnt(0), idx(-1), parent(nullptr) {
		for(int x=0;x<2;x++){
			child[x] = nullptr;
		}
	}
	
	Vertex(Vertex *parent) : cnt(0), idx(-1), parent(parent) {
		for(int x=0;x<2;x++){
			child[x] = nullptr;
		}
	}
};

DSU dsu;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	pair<int, int> v[n];
	for(int x=0;x<n;x++){
		cin >> v[x].first;
		v[x].second = x;
	}
	
	sort(v, v+n);
	
	dsu.reset();
	Vertex *trie = new Vertex();
	
	for(int x=0;x<n;x++){
		Vertex *cur = trie;
		int val = 0;
		for(int i=29;i>=0;i--){
			int bit = (1 << i);
			
			int idx = (v[x].first&bit) != 0;
			if(cur->child[idx] && cur->child[idx]->cnt > 0){
				cur = cur->child[idx];
			} else {
				val |= bit;
				if(!cur->child[idx^1]){
					cur->child[idx^1] = new Vertex(cur);
				}
				cur = cur->child[idx^1];
			}
		}
		
		if(val <= m && cur->idx >= 0){
			dsu.merge(cur->idx, v[x].second);
		}
		
		cur = trie;
		
		for(int i=29;i>=0;i--){
			int bit = (1 << i);
			
			int idx = (v[x].first&bit) != 0;
			if(!cur->child[idx]){
				cur->child[idx] = new Vertex(cur);
			}
			cur = cur->child[idx];
		}
		
		if(cur->idx == -1) cur->idx = v[x].second;
		while(cur){
			cur->cnt++;
			cur = cur->parent;
		}
	}
	
	for(int i=0;i<q;i++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		cout << (dsu.getParent(a) == dsu.getParent(b) ? "YES" : "NO") << "\n";
	}
    return 0;
}

