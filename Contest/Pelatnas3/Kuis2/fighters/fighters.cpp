#include "fighters.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long minimum_strength(std::vector<int> A, std::vector<int> B) {
	int N = A.size();
	int M = B.size();
	
	vector<pair<int, int>> v, w;
	for(int x=0;x<N;x++){
		v.push_back({A[x], x});
	}
	for(int x=0;x<M;x++){
		w.push_back({B[x], x});
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	
	for(int x=0;x<M;x++){
		if(v.size() == M) break;
		
		vector<int> order(M, -1);
		order[w.back().second] = v[x].second;
		for(int y=1;y<M;y++){
			order[w[y-1].second] = v.back().second;
			v.pop_back();
		}
		v[x].first += w.back().first;
		
//		cout << v.size() << endl;
		fight(order);
	}
	
	vector<int> order(M, -1);
	order[w.back().second] = v[M-1].second;
	
	int mx = w.back().first+v[M-1].first;
	for(int y=0;y<M-1;y++){
		order[w[y].second] = v[y].second;
		mx = max(mx, w[y].first+v[y].first);
	}
	fight(order);
	
	return mx;
}
