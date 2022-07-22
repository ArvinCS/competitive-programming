#include "art.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> calculate_steps(int N, vector<int> A) {
	ll table[N][N+1];
	fill(table[0], table[N], 1e18);
	
	for(int x=0;x<N;x++){
		table[x][0] = 0;
	}
	
	vector<int> ans;
	for(int x=1;x<=(N+1)/2;x++){
		ll mn = 1e18;
		
		ll best = (x > 1 ? 1e18 : 0);
		for(int y=0;y<N;y++){
			if(y-3 >= 0){
				best = min(best, table[y-3][x-1]);	
			}
			if(y-2 >= 0 && x > 1){
				table[y][x] = table[y-2][x-1] + max(0, min(A[y-2]-1, A[y-1])-A[y]+1) + (y+1 < N ? max(0, A[y+1]-A[y]+1) : 0);
			}
			
			table[y][x] = min(table[y][x], (y > 0 ? max(0, A[y-1]-A[y]+1) : 0) + (y+1 < N ? max(0, A[y+1]-A[y]+1) : 0) + best);
			mn = min(mn, table[y][x]);
		}
		
		ans.push_back(mn);
	}
	
	return ans;
}
