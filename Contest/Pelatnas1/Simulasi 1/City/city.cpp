#include <bits/stdc++.h>
#include "city.h"

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const pair<ll, int> mxP = make_pair(1e18, 1e9);

struct DSU {
	int parrent[maxN], sz[maxN], mn[maxN];
	
	void reset(int n){
		for(int x=0;x<n;x++){
			parrent[x] = x;
			mn[x] = x;
			sz[x] = 1;
		}
	}	
	
	int getParrent(int x){
		if(parrent[x] == x) return x;
		return parrent[x] = getParrent(parrent[x]);
	}
	
	void merge(int x, int y){
		int a = getParrent(x);
		int b = getParrent(y);
		
		if(a != b){
			if(sz[a] < sz[b]) swap(a, b);
			
			parrent[b] = a;
			mn[a] = min(mn[a], mn[b]);
			sz[a] += sz[b];
		}
	}
};

DSU dsu;
ll dist[maxN][2];
vector<pair<int, int>> adj[maxN];

void dijkstra(int source, int id){
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[source][id] = 0;
	pq.push({dist[source][id], source});
	
	
	while(!pq.empty()){
		pair<ll, int> p = pq.top();
		pq.pop();
		
		if(dist[p.second][id] < p.first) continue;
		for(auto nxt : adj[p.second]){
			if(dist[nxt.first][id] > p.first+nxt.second){
				dist[nxt.first][id] = p.first+nxt.second;
				pq.push({dist[nxt.first][id], nxt.first});
			}
		}
	}
}

pair<int, int> getBestXY(int N, int M, int S, int T, vector<int> A, vector<int> B, vector<int> C) {
	vector<pair<int, int>> v;
	for(int x=0;x<M;x++){
		v.push_back({C[x], x});
		adj[A[x]].push_back({B[x], C[x]});
		adj[B[x]].push_back({A[x], C[x]});
	}
	
	sort(v.begin(), v.end());
	fill(dist[0], dist[maxN], 1e18);
	dsu.reset(N);
	
	int mx = 0;
	for(int x=0;x<M;x++){
		int idx = v[x].second;
		if(dsu.getParrent(A[idx]) != dsu.getParrent(B[idx])){
			mx = C[idx];
			dsu.merge(A[idx], B[idx]);		
		}
	}
	
	dijkstra(S, 0);
	dijkstra(T, 1);
	
	dsu.reset(N);
	for(int x=0;x<M;x++){
		int idx = v[x].second;
		if(C[idx] >= mx) break;
		if(dsu.getParrent(A[idx]) != dsu.getParrent(B[idx])){
			dsu.merge(A[idx], B[idx]);		
		}
	}
	
	map<int, pair<ll, int>> mp, mp2;
	for(int x=0;x<N;x++){
		if(mp.find(dsu.getParrent(x)) != mp.end()){
			mp[dsu.getParrent(x)] = min(mp[dsu.getParrent(x)], {dist[x][0], x});
		} else {
			mp[dsu.getParrent(x)] = {dist[x][0], x};
		}
		
		if(mp2.find(dsu.getParrent(x)) != mp2.end()){
			mp2[dsu.getParrent(x)] = min(mp2[dsu.getParrent(x)], {dist[x][1], x});
		} else {
			mp2[dsu.getParrent(x)] = {dist[x][1], x};
		}
	}
	
	pair<ll, int> mn[mp.size()][2], prefix[mp.size()][2], suffix[mp.size()][2];
	int prefixIdx[mp.size()], suffixIdx[mp.size()];
	int idx = 0;
	map<int, int> mp3;
	for(auto p : mp){
		mn[idx][0] = p.second;
		mn[idx][1] = mp2[p.first];
		mp3[p.first] = idx;
		prefixIdx[idx] = suffixIdx[idx] = dsu.mn[dsu.getParrent(p.first)];
		idx++;
	}
	for(int x=0;x<idx;x++){
		prefix[x][0] = min(mn[x][0], (x > 0 ? prefix[x-1][0] : mxP));
		prefix[x][1] = min(mn[x][1], (x > 0 ? prefix[x-1][1] : mxP));
		prefixIdx[x] = min(prefixIdx[x], (x > 0 ? prefixIdx[x-1] : prefixIdx[x]));
	}
	for(int x=idx-1;x>=0;x--){
		suffix[x][0] = min(mn[x][0], (x+1 < idx ? suffix[x+1][0] : mxP));
		suffix[x][1] = min(mn[x][1], (x+1 < idx ? suffix[x+1][1] : mxP));
		suffixIdx[x] = min(suffixIdx[x], (x+1 < idx ? suffixIdx[x+1] : suffixIdx[x]));
	}
	
	ll mxDist = 1e18;
	pair<int, int> result = {1e9, 1e9};
	
	for(int x=0;x<M;x++){
		if(C[x] == mx && dsu.getParrent(A[x]) != dsu.getParrent(B[x])){
			int pA = mp3[dsu.getParrent(A[x])], pB = mp3[dsu.getParrent(B[x])];
			
			pair<int, int> p = {1e9, 1e9};
			
			{
				int mnIdx = min((pA > 0 ? prefixIdx[pA-1] : 1e9), (pA+1 < idx ? suffixIdx[pA+1] : 1e9));
				p = min(p, make_pair(min(mnIdx, dsu.mn[dsu.getParrent(A[x])]), max(mnIdx, dsu.mn[dsu.getParrent(A[x])])));
			}
			{
				int mnIdx = min((pB > 0 ? prefixIdx[pB-1] : 1e9), (pB+1 < idx ? suffixIdx[pB+1] : 1e9));
				p = min(p, make_pair(min(mnIdx, dsu.mn[dsu.getParrent(B[x])]), max(mnIdx, dsu.mn[dsu.getParrent(B[x])])));
			}
			
			ll best = dist[T][0];
			for(int i=0;i<2;i++){
				pair<ll, int> mnA = min((pA > 0 ? prefix[pA-1][i] : mxP), (pA+1 < idx ? suffix[pA+1][i] : mxP));
				pair<ll, int> mnB = min((pB > 0 ? prefix[pB-1][i] : mxP), (pB+1 < idx ? suffix[pB+1][i] : mxP));
				
//				cout << i << ": " << mnA.second << " " << mn[pA][i^1].second << " " << mnB.first+mn[pB][i^1].first << "\n";
//				cout << pA << " " << mn[pA-1][i].first << " " << (pA > 0 ? prefix[pA-1][i] : mxP).first << " " << (pA+1 < idx ? suffix[pA+1][i] : mxP).first << "\n";
				if(best > mnA.first+mn[pA][i^1].first){
					int a = min(mnA.second, mn[pA][i^1].second);
					int b = max(mnA.second, mn[pA][i^1].second);
					
					p = {a, b};
					best = mnA.first+mn[pA][i^1].first;
				}
				if(best > mnB.first+mn[pB][i^1].first){
					int a = min(mnB.second, mn[pB][i^1].second);
					int b = max(mnB.second, mn[pB][i^1].second);
					
					p = {a, b};
					best = mnB.first+mn[pB][i^1].first;
				}
			}
			
			if(best < mxDist){
				mxDist = best;
				result = p;
			} else if(best == mxDist){
				result = min(result, p);
			}
		}
	}
	
//	cout << mxDist << "\n";
	return result;
}
