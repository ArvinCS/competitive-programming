#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 4e5 + 5;

vector<pair<int, int>> adj[maxN];
int val[maxN];

struct DSU {
	int parent[maxN], sz[maxN];
	int n;
	
	void build(int n){
		this->n = n;
		for(int x=0;x<n;x++){
			parent[x] = x;
			sz[x] = 1;
			val[x] = 0;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void merge(int x, int y, int w){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
			
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
	
	int getSize(){
		return n;
	}
};

DSU dsu;
bool visited[maxN];

void dfs(int curNode, int prvNode, int w){
	val[curNode] = w;
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			dfs(nxt.first, curNode, w^nxt.second);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	vector<int> v;
	array<int, 4> t[q];
	for(int x=0;x<q;x++){
		cin >> t[x][0] >> t[x][1] >> t[x][2];
		t[x][1]--;
		if(t[x][0] == 1) cin >> t[x][3];
		
		v.push_back(t[x][1]); v.push_back(t[x][2]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	dsu.build(v.size());
	
	bool valid[q];
	fill(valid, valid+q, true);
	fill(val, val+v.size(), 0);
	
	for(int x=0;x<q;x++){
		int l = t[x][1], r = t[x][2];
		l = t[x][1] = lower_bound(v.begin(), v.end(), l) - v.begin();
		r = t[x][2] = lower_bound(v.begin(), v.end(), r) - v.begin();
		
		if(t[x][0] == 1){
			if(dsu.getParent(l) == dsu.getParent(r)){
				continue;
			}
			
			dsu.merge(l, r, t[x][3]);
		} else if(t[x][0] == 2){
			if(dsu.getParent(l) != dsu.getParent(r)){
				valid[x] = false;
				continue;
			}
		}
	}
	
	fill(visited, visited+v.size(), false);
	
	for(int x=0;x<v.size();x++){
		if(!visited[x]){
			dfs(x, x, 0);
		}
	}
	
	for(int x=0;x<q;x++){
		int l = t[x][1], r = t[x][2];
		
		if(t[x][0] == 2){
			if(valid[x]){
				cout << (val[r]^val[l]) << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}
    return 0;
}

