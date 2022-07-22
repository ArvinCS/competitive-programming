#include "dango3.h"
#include <bits/stdc++.h>

using namespace std;

void Solve(int n, int m) {
	int len = n*m;
	
	vector<int> comp[m+1];
	int idx = 0;
	
	comp[idx].push_back(1);
	for(int x=2;x<=len;x++){
		int pos = idx+1;
		int left = 0, right = idx;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			bool exist[len+1];
			fill(exist, exist+len+1, true);
			
			exist[x] = false;
			for(int y=0;y<=mid;y++){
				for(auto idx : comp[y]){
					exist[idx] = false;
				}
			}
			
			vector<int> w;
			for(int y=1;y<=len;y++){
				if(exist[y]) w.push_back(y);
			}
			
			if(Query(w) == m-(mid+1)){
				pos = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		comp[pos].push_back(x);
		idx = max(idx, pos);
	}
	
	for(int x=0;x<m;x++){
		vector<int> w;
		for(int y=0;y<n;y++){
			w.push_back(comp[x][y]);
		}
		
		Answer(w);
	}
}
