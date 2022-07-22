#include "server.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 505;

int n;
vector<int> ans(1000, 0);
vector<pair<int, int>> adj[maxN];
int sz[maxN], root[maxN];

void dfs(int curNode, int prvNode){
	sz[curNode] = 1;
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			ans[nxt.first] = nxt.second;
			dfs(nxt.first, curNode);
			sz[curNode] += sz[nxt.first];
		}
	}
}

void hld(int curNode, int prvNode, int r, int cnt){
	root[curNode] = r;
	ans[n+curNode] = cnt;
	
	int mx = 0, idx = -1;
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			if(sz[nxt.first] > mx){
				mx = sz[nxt.first];
				idx = nxt.first;
			}
		}
	}
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			if(nxt.first == idx){
				hld(nxt.first, curNode, r, cnt+nxt.second);
			} else {
				hld(nxt.first, curNode, nxt.first, 0);
			}
		}
	}
}

vector<int> server(int N, vector<int> A, vector<int> B, vector<int> C) {
	n = N-1;
	for(int x=0;x<N-1;x++){
		adj[A[x]].push_back({B[x], C[x]});
		adj[B[x]].push_back({A[x], C[x]});
	}
	
	dfs(0, 0);
	hld(0, 0, 0, 0);
	return ans;
}
