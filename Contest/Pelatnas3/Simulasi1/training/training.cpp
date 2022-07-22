#include "training.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;
const int logN = log2(maxN)+1;

struct DSU {
	int parent[maxN], sz[maxN];
//	int parent[logN][2*maxN], level[2*maxN], val[2*maxN], idx = maxN;
//	vector<int> adj[2*maxN];
	
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
//	bool merge(int x, int y, int cost = 0){
//		int a = getParent(x);
//		int b = getParent(y);
//		
//		if(a == b) return false;
//		
//		adj[idx].push_back(a);
//		adj[idx].push_back(b);
//		val[idx] = cost;
//		
//		parent[0][a] = idx;
//		parent[0][b] = idx;
//		idx++;
//		
//		return true;
//	}
//	
//	void dfs(int curNode){
//		for(int x=1;x<logN;x++){
//			parent[x][curNode] = parent[x-1][parent[x-1][curNode]];
//		}
//		for(auto nxt : adj[curNode]){
//			level[nxt] = level[curNode]+1;
//			parent[0][nxt] = curNode;
//			dfs(nxt);
//		}
//	}
//	
//	int findLCA(int a, int b){
//		if(level[a] > level[b]) swap(a, b);
//		
//		for(int x=logN-1;x>=0;x--){
//			if(level[a] <= level[b]-(1 << x)){
//				b = parent[x][b];
//			}
//		}
//		
//		if(a == b) return a;
//		
//		for(int x=logN-1;x>=0;x--){
//			if(parent[x][a] != parent[x][b]){
//				a = parent[x][a];
//				b = parent[x][b];
//			}
//		}
//		
//		return parent[0][a];
//	}
} dsu;

vector<pair<int, int>> adj[maxN];

std::vector<int> find_training_routes(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
	int M = A.size();
	
//	vector<int> w;
	vector<pair<int, int>> edge;
	for(int x=0;x<M;x++){
		edge.push_back({C[x], x});
	}
	
	sort(edge.begin(), edge.end());
//	sort(w.begin(), w.end());
//	w.erase(unique(w.begin(), w.end()), w.end());
	
	dsu.reset();
	for(auto p : edge){
		if(dsu.merge(A[p.second], B[p.second])){
			adj[A[p.second]].push_back({B[p.second], p.first});
			adj[B[p.second]].push_back({A[p.second], p.first});
		}
	}
	
	vector<int> ans(N, 2e9);
	
	int dist[N];
//	for(int x=0;x<w.size();x++){
		fill(dist, dist+N, 1e9);
		
		dist[0] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 0});
		
		while(!pq.empty()){
			pair<int, int> p = pq.top();
			pq.pop();
			
			if(dist[p.second] < p.first) continue;
			for(auto nxt : adj[p.second]){
				if(dist[nxt.first] > max(p.first, nxt.second)){
					dist[nxt.first] = max(p.first, nxt.second);
					pq.push({dist[nxt.first], nxt.first});
				}
			}
		}
		
		ans[0] = 0;
		for(int y=1;y<N;y++){
//			cout << w[x] << " " << y << " -> " << dist[y] << "\n";
			ans[y] = min(ans[y], ((int) 1e9) + dist[y]);
		}
//	}
	return ans;
}
