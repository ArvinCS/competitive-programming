#include "reverse.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> reverse_array(int N) {
	vector<vector<int>> ans;
	
	if(N == 1){
		return ans;
	}
	if(N == 2){
		ans.push_back({1, 1, 2});
		return ans;
	}
	
	int mid = N/2;
	ans.push_back({mid+1, N-(N%2), 0});
	
	int pos = N;
	for(int x=N-(N%2)-mid;x>=1;x--){
		ans.push_back({x, x+1, pos--});
	}
	return ans;
}
