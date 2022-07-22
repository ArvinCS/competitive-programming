#include "experiment.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxM = 3e5 + 5;

struct Fenwick {
	int tree[maxM];
	
	void reset(){
		fill(tree, tree+maxM, 0);
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxM){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
};

Fenwick leftPart, rightPart;

vector<long long> get_experiment_results(int N, int M,
                                              vector<int> P, vector<int> Q,
                                              vector<int> L, vector<int> R,
                                              vector<int> D, vector<int> U) {
	vector<ll> ans(M, 0);
	leftPart.reset();
	rightPart.reset();
	
	vector<tuple<int, int, int>> v;
	for(int x=0;x<N;x++){
		rightPart.update(Q[x], 1);
		v.push_back(make_tuple(P[x], 1, x));
	}
	for(int x=0;x<M;x++){
		v.push_back(make_tuple(L[x], 0, x));
		v.push_back(make_tuple(R[x], 2, x));
	}
	
	sort(v.begin(), v.end());
	
	bool used[M];
	fill(used, used+M, false);
	
	int checkpoint[M][3];
	fill(checkpoint[0], checkpoint[M], 0);
	
	for(auto t : v){
		int pos = get<0>(t), idx = get<2>(t);
		bool atom = (get<1>(t) == 1);
		
		if(atom){
			rightPart.update(Q[idx], -1);
			leftPart.update(Q[idx], 1);
		} else {
			if(used[idx]){
				ans[idx] += (rightPart.query(N) - rightPart.query(D[idx]-1)) * 1ll * (leftPart.query(D[idx]-1) - checkpoint[idx][0]);
				ans[idx] += rightPart.query(N) * 1ll * (leftPart.query(U[idx]) - leftPart.query(D[idx]-1) - checkpoint[idx][1]);
				ans[idx] += rightPart.query(U[idx]) * 1ll * (leftPart.query(N) - leftPart.query(U[idx]) - checkpoint[idx][2]);
				
				// special case
				ans[idx] += (leftPart.query(D[idx]-1) - checkpoint[idx][0]) * 1ll * (leftPart.query(N) - leftPart.query(D[idx]-1) - checkpoint[idx][1] - checkpoint[idx][2]);
				ans[idx] += (leftPart.query(U[idx]) - leftPart.query(D[idx]-1) - checkpoint[idx][1]) * 1ll * (leftPart.query(U[idx]) - leftPart.query(D[idx]-1) - checkpoint[idx][1] - 1) / 2;
				ans[idx] += (leftPart.query(U[idx]) - leftPart.query(D[idx]-1) - checkpoint[idx][1]) * 1ll * (leftPart.query(N) - leftPart.query(U[idx]) - checkpoint[idx][2]);
			} else {
				ans[idx] += (rightPart.query(N) - rightPart.query(D[idx]-1)) * 1ll * leftPart.query(D[idx]-1);
				ans[idx] += rightPart.query(N) * 1ll * (leftPart.query(U[idx]) - leftPart.query(D[idx]-1));
				ans[idx] += rightPart.query(U[idx]) * 1ll * (leftPart.query(N) - leftPart.query(U[idx]));
				
				checkpoint[idx][0] = leftPart.query(D[idx]-1);
				checkpoint[idx][1] = (leftPart.query(U[idx]) - leftPart.query(D[idx]-1));
				checkpoint[idx][2] = (leftPart.query(N) - leftPart.query(U[idx]));
			}
			
			used[idx] = true;
		}
	}
	
	return ans;
}
