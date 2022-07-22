#include "server.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 25;

int ans[maxN];
vector<pair<int, int>> adj[maxN];

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			ans[nxt.first] = nxt.second;
			dfs(nxt.first, curNode);
		}
	}
}

std::vector<int> server(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
	for(int x=0;x<N;x++) adj[x].clear();
	for(int x=0;x<N-1;x++){
		adj[A[x]].push_back({B[x], C[x]});
		adj[B[x]].push_back({A[x], C[x]});
	}
	
	fill(ans, ans+N, 0);
	
	dfs(0, -1);
	
	vector<int> v;
	for(int x=0;x<N;x++){
		v.push_back(ans[x]);
	}
	return v;
}
