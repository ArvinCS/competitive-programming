#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e3 + 5;

vector<int> adj[2*maxN];

struct DSU {
	int parent[maxN], sz[maxN];
	vector<int> v[maxN][2];
	
	void reset(int n){
		for(int x=0;x<2*n;x++){
			parent[x] = x;
			sz[x] = 1;
			if(x < n) v[x][0].push_back(x);
			else v[x][1].push_back(x);
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
			for(int x=0;x<2;x++){
				while(!v[b][x].empty()){
					v[a][x].push_back(v[b][x].back());
					v[b][x].pop_back();
				}
			}
			sz[a] += sz[b];
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	DSU dsu;
	dsu.reset(n);
	
	int a[2*n], b[2*n];
	for(int x=0;x<2*n;x++){
		cin >> a[x] >> b[x];
		
		a[x]--; b[x]--;
		adj[a[x]].push_back(b[x]);
		adj[b[x]].push_back(a[x]);
		dsu.merge(a[x], b[x]);
	}
	
	for(int x=0;x<2*n;x++){
		if(dsu.getParent(x) == x){
			
		}
	}
    return 0;
}

