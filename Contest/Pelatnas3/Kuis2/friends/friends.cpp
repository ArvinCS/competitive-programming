#include "friends.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = log2(maxN)+1;
const ll mod = 1e9 + 7;

vector<pair<int, ll>> adj[maxN];
int level[maxN];
pair<int, ll> parent[maxN];
ll dist[maxN];
vector<pair<int, ll>> v[maxN];
int M = -1;

void dfs(int curNode, int prvNode){
	for(auto nxt : adj[curNode]){
		if(nxt.first != prvNode){
			level[nxt.first] = level[curNode]+1;
			dist[nxt.first] = dist[curNode]+nxt.second;
			parent[nxt.first] = {curNode, nxt.second};
			dfs(nxt.first, curNode);
		}
	}
}

ll dfs2(int curNode, int prvNode){
	ll ans = 0;
	
	pair<int, int> mx = {0, -1};
	for(auto nxt : adj[curNode]){
		if(nxt.first != parent[curNode].first){
			ans += dfs2(nxt.first, curNode);
			if(ans >= mod) ans -= mod;
			
			mx = max(mx, {v[nxt.first].size(), nxt.first});
		}
	}
	
	if(v[curNode].size() < mx.first){
		swap(v[curNode], v[mx.second]);
	}
	for(auto p : v[mx.second]){
		v[curNode].push_back(p);
	}	
	v[mx.second].clear();
	
	for(auto nxt : adj[curNode]){
		if(nxt.first != parent[curNode].first && nxt.first != mx.second){
			for(auto p : v[nxt.first]){
				v[curNode].push_back(p);
			}	
			v[nxt.first].clear();
		}
	}
	
	sort(v[curNode].begin(), v[curNode].end());
	
	for(int x=0;x<M;x++){
		for(int y=x+1;y<M;y+=2){
			auto it = lower_bound(v[curNode].begin(), v[curNode].end(), make_pair(x, -1ll));
			auto it2 = lower_bound(v[curNode].begin(), v[curNode].end(), make_pair(y+1, -1ll));
			
			int cnt = ((it2 - v[curNode].begin()) - (it - v[curNode].begin()));
			ans += parent[curNode].second * 1ll * (cnt / 2 * 2) % mod;
			cout << curNode << " " << x << "-" << y << " -> " << parent[curNode].second * 1ll * (cnt / 2 * 2) % mod << "\n";
			if(ans >= mod) ans -= mod;
		}
	}
	
	return ans;
}

int pairing_sum(std::vector<int> U, std::vector<int> V, std::vector<int> W, std::vector<int> H) {
	int N = U.size() + 1;
	M = H.size();
	
	for(int x=0;x<N-1;x++){
		adj[U[x]].push_back({V[x], W[x]});
		adj[V[x]].push_back({U[x], W[x]});
	}
	
	dist[0] = 0;
	level[0] = 0;
	parent[0] = {0, 0};
	dfs(0, 0);
	
	ll ans = 0;
	for(int x=0;x<M;x++){
		v[H[x]].push_back({x, H[x]});
		
		int oddL = (x+2)/2;
		int oddR = (M-x+(x&1))/2;
		int evenL = (x+1)/2;
		int evenR = (M-x+(x%2==0))/2;
		
		ans += dist[H[x]] * (oddL * oddR - (x&1)) % mod * (evenL * evenR - (x%2==0)) % mod;
		if(ans >= mod) ans -= mod;
	}
	
	ans -= dfs2(0, 0);
	if(ans < 0) ans += mod;
	if(ans >= mod) ans -= mod;
	
	return ans;
}
