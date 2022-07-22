#include "swap.h"
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 1e5 + 50;
const int maxM = 2e5 + 50;
const int maxSz = maxN+maxM;
const int logNM = log2(maxN+maxM)+1;

int n, m, idx = 0;
int parrent[maxSz];
vector<int> adj[maxSz];
int root[logNM+2][maxSz], depth[maxSz], cost[maxSz];
bool safe[maxSz];

int getParrent(int x){
	if(parrent[x] == x) return x;
	return parrent[x] = getParrent(parrent[x]);
}

void merge(int x, int y, int c){
	int a = getParrent(x);
	int b = getParrent(y);
	
	parrent[idx] = idx;
	parrent[a] = parrent[b] = idx;
	cost[idx] = c;
	safe[idx] |= (safe[a] | safe[b]);
	
//	cout << a << " " << b << " | " << parrent[a] << " " << parrent[b] << "\n";
	adj[idx].push_back(a);
	if(a != b) adj[idx].push_back(b);	
	idx++;
}

void dfs(int curNode, int prvNode){
//	cout << prvNode << " visited " << curNode << "\n";
	for(int x=1;x<=logNM;x++){
		root[x][curNode] = root[x-1][root[x-1][curNode]];
	}
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			depth[nxt] = depth[curNode]+1;
			root[0][nxt] = curNode;
			dfs(nxt, curNode);
		}
	}
}

void init(int N, int M, vector<int> u, vector<int> v, vector<int> w){
	n = N;
	m = M;
	
	vector<tuple<int, int, int>> edge;
	for(int x=0;x<m;x++){
		edge.push_back(make_tuple(w[x], u[x], v[x]));
	}
	
	sort(edge.begin(), edge.end());
	
	for(int x=0;x<n;x++){
		parrent[x] = x;	
		cost[x] = 0;
		idx++;
	}
	
	int cnt[n+m];
	fill(cnt, cnt+n+m, 0);
	fill(safe, safe+n+m, false);
	
	for(int x=0;x<m;x++){
		tuple<ll, int, int> t = edge[x];
		int cost = get<0>(t);
		int a = get<1>(t), b = get<2>(t);
		
		if(cnt[a] > 1 || cnt[b] > 1 || getParrent(a) == getParrent(b)){
			safe[idx] = true;
		}
		
		cnt[a]++;
		cnt[b]++;
		merge(a, b, cost);
	}
	
	root[0][idx-1] = idx-1;
	depth[idx-1] = 0;
	dfs(idx-1, idx-1);
}

int getMinimumFuelCapacity(int a, int b){
	if(depth[a] > depth[b]) swap(a, b);
	
//	bool same = (depth[a] == depth[b]);
//	ll origin = query(inTime[b]);
	for(int x=logNM;x>=0;x--){
		if(depth[a] <= depth[root[x][b]]){
			b = root[x][b];
		}
	}
	
	for(int x=logNM;x>=0;x--){
		if(root[x][a] != root[x][b]){
			a = root[x][a];
			b = root[x][b];
		}
	}
	
	for(int x=logNM;x>=0;x--){
		if(!safe[root[x][a]] && !safe[root[x][b]]){
			a = root[x][a];
			b = root[x][b];
		}
	}
	
//	cout << a << " " << depth[a] << " " << root[0][a] << " " << cost[a] << " " << cost[root[0][a]] << "\n";
	if(!safe[root[0][a]]) return -1;
	return cost[root[0][a]];
}
