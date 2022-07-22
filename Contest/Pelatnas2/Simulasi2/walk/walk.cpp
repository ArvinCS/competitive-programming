#include "walk.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 41;

vector<pair<int, int>> adj[maxN], rev_adj[maxN];
vector<ll> w; 
bool visited[maxN];

void dfs(int curNode, vector<int> &v){
	visited[curNode] = true;
	
	for(auto nxt : adj[curNode]){
		if(!visited[nxt.first]){
			dfs(nxt.first, v);
		}		
	}
	
	v.push_back(curNode);
}

void dfs2(int curNode, vector<int> &v){
	visited[curNode] = true;
	
	for(auto nxt : rev_adj[curNode]){
		if(!visited[nxt.first]){
			dfs(nxt.first, v);
		}		
	}
	
	v.push_back(curNode);
}

long long find_best_walk(int N, long long K, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
	int m = U.size();
	for(int x=0;x<m;x++){
		adj[U[x]].push_back({V[x], W[x]});
		rev_adj[V[x]].push_back({U[x], W[x]});
	}	
	
	vector<pair<int, int>> v;
	priority_queue<ll> pq;
	queue<array<int, 4>> q[4];
	for(int x=0;x<N;x++){
		q[0].push({0, x, (1 << x), x});
//		cout << 0 << " " << x << " " << (1 << x) << " --\n";
	}
	
	int idx = 0;
	int cur = 0;
	int cnt = 0;
	while(!q[0].empty() || !q[1].empty() || !q[2].empty() || !q[3].empty()){
		while(q[cur].empty()){
			cur++;
			if(cur >= 4) cur -= 4;
		}
		
		while(!q[cur].empty()){
			array<int, 4> a = q[cur].front();
			q[cur].pop();
			
			if(a[0] > 0) cnt++;
			if(a[0] > 0 && cnt == K) return a[0];
			for(auto nxt : adj[a[1]]){
				q[(cur+nxt.second)%4].push({a[0]+nxt.second, nxt.first, a[2]|(1 << nxt.first), a[3]});
			}
		}
	}
	
	return -1;
}
