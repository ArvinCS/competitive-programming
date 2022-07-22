#include "trainer.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll inf = 1e18;

ll minimize_penalty(std::vector<int> L, std::vector<int> R, std::vector<std::vector<int>> A) {
	int K = L.size();
	int M = A.size();
	int N = A[0].size() / 2;
	
	vector<pair<int, int>> w;
	for(int x=0;x<K;x++){
		w.push_back({L[x], R[x]});
	}
	
	sort(w.begin(), w.end());
	
	vector<pair<int, int>> z;
	int mx = -1;
	for(auto p : w){
		if(mx < p.second){
			z.push_back({p.first, p.second});
			mx = p.second;
		}
	}
	
	swap(w, z);
	
	for(int x=0;x<M;x++){
		sort(A[x].begin(), A[x].end());
	}
	
	vector<pair<int, ll>> v[N];
	for(int x=0;x<M;x++){
		for(int y=0;y<N;y++){
			v[y].push_back({A[x][2*y], A[x][2*y]});
			v[y].push_back({A[x][2*y+1], A[x][2*y+1]});
		}
	}
	
	for(int x=0;x<N;x++){
		sort(v[x].begin(), v[x].end());
		for(int y=1;y<v[x].size();y++){
			v[x][y].second += v[x][y-1].second;
		}
	}
	
	auto cost = [&](int x, int y) -> ll {
		ll left = lower_bound(v[x].begin(), v[x].end(), make_pair(w[y].first, -inf)) - v[x].begin();
		ll right = lower_bound(v[x].begin(), v[x].end(), make_pair(w[y].second+1, -inf)) - v[x].begin();
		
		if(left > 0){
			left = left*w[y].first - v[x][left-1].second;
		} else {
			left = 0;
		}
		
		if(right > 0){
			right = (v[x].back().second - v[x][right-1].second) - (2*M-right)*w[y].second;
		} else {
			right = v[x].back().second - (2*M-right)*w[y].second;
		}
		
		return left+right;
	};
	
	auto dnc = [&](auto &self, int l, int r, int lk, int rk) -> ll {
		if(l > r) return 0;
		
		pair<ll, int> mn = {1e18, 1e9};
		
		int m = (l+r) >> 1;
		for(int x=lk;x<=rk;x++){
			mn = min(mn, {cost(m, x), x});
		}
		
		return mn.first + self(self, l, m-1, lk, mn.second) + self(self, m+1, r, mn.second, rk);
	};
	
	return dnc(dnc, 0, N-1, 0, w.size()-1);
}
