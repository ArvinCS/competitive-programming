#include "game.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct DSU {
	int parent[maxN], sz[maxN];
	bool specialStart[maxN], specialEnd[maxN];
	
	void reset(int n){
		for(int x=0;x<=n;x++){
			parent[x] = x;
			sz[x] = 1;
			specialStart[x] = specialEnd[x] = false;
		}
	}	
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void toggleStart(int x, bool val){
		specialStart[getParent(x)] = val;	
	}
	
	void toggleEnd(int x, bool val){
		specialEnd[getParent(x)] = val;	
	}
	
	bool query(int x){
		return (specialStart[getParent(x)] && specialEnd[getParent(x)]);
	}
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parent[b] = a;
			sz[a] += sz[b];
			specialStart[a] |= specialStart[b];
			specialEnd[a] |= specialEnd[b];
		}
	}
} dsu;

vector<int> adj[maxN], rev_adj[maxN];
int idxEnd[maxN];
int n;
int k;

void init(int N, int K) {
	n = N;
	k = K;
	
	fill(idxEnd, idxEnd+n, 1e9);
	
	for(int x=1;x<k;x++){
		adj[x-1].push_back(x);
		rev_adj[x].push_back(x-1);
	}
}

int add_teleporter(int u, int v) {
	adj[u].push_back(v);
	rev_adj[v].push_back(u);
	
	if((u >= k && v < k) || (u < k && v < k && u >= v) || idxEnd[v] < idxEnd[u]){
		if(v < k){
			idxEnd[u] = min(v, idxEnd[v]);
		} else {
			idxEnd[u] = idxEnd[v];
		}
		
		queue<int> q;
		q.push(u);
		
		while(!q.empty()){
			int curNode = q.front();
			q.pop();
			
//			cout << curNode << " " << idxEnd[curNode] << " = " << u << " " << v << endl;
			if(curNode < k && idxEnd[curNode] <= curNode){
				return 1;
			}
			
			for(auto nxt : rev_adj[curNode]){
				if(idxEnd[nxt] > idxEnd[curNode]){
					idxEnd[nxt] = idxEnd[curNode];
					q.push(nxt);
				}
			}
		}
	}
	
	return 0;
}
