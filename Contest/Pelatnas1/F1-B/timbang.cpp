#include "timbang.h"
#include <vector>

std::vector<int> v;

void merge(int l, int r){
	if(l == r) return;
	
	int m = (l+r) >> 1;	
	merge(l, m);
	merge(m+1, r);
	
	int curL = l, curR = m+1;
	std::vector<int> w;
	while(curL <= m && curR <= r){
		if(compare(v[curL], v[curR]) == -1){
			w.push_back(v[curL++]);
		} else {
			w.push_back(v[curR++]);
		}
	}
	while(curL <= m){
		w.push_back(v[curL++]);
	}
	while(curR <= r){
		w.push_back(v[curR++]);
	}
	
	for(int x=0;x<w.size();x++){
		v[l+x] = w[x];
	}
}

std::vector<int> findOrder(int N, int K) {
	for(int x=1;x<=N;x++){
		v.push_back(x);
	}
	
	merge(0, N-1);	
    return v;
}
