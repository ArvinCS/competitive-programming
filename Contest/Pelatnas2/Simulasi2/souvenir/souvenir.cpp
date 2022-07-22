#include "souvenir.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct SegmentTree {
	ll tree[4*maxN], lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}	
	
	void push(int v){
		tree[2*v+1] += lazy[v];
		lazy[2*v+1] += lazy[v];
		
		tree[2*v+2] += lazy[v];
		lazy[2*v+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(curL > curR || l > r || curR < l || curL > r) return;
		
		if(l <= curL && curR <= r){
			tree[v] += val;
			lazy[v] += val;
			return;
		}
		
		int curM = (curL+curR)>>1;
		
		push(v);
		update(2*v+1, curL, curM, l, min(r, curM), val);
		update(2*v+2, curM+1, curR, max(l, curM+1), r, val);
		
		tree[v] = max(tree[2*v+1], tree[2*v+2]);
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return 0;
		
		if(curL == l && curR == r){
			return tree[v];
		}
		
		int curM = (curL+curR)>>1;
		
		push(v);
		
		return max(query(2*v+1, curL, curM, l, min(r, curM)), query(2*v+2, curM+1, curR, max(l, curM+1), r));
	}
};

SegmentTree tree;

long long buy_souvenir(std::vector<int> A, std::vector<int> X, std::vector<int> B, std::vector<int> Y) {
	int n = A.size();
	int m = B.size();
	
	tree.reset();
	int pos[n+m];
	fill(pos, pos+n+m, -1);
	
	for(int x=0;x<n;x++){
		pos[A[x]] = x;	
	}
	
	ll suffix[n+1];
	suffix[n] = 0;
	for(int x=n-1;x>=0;x--){
		suffix[x] = (suffix[x+1] + X[x]);
		tree.update(0, 0, n-1, x, x, suffix[x]);
	}
	
	set<array<int, 3>> st2;
	ll ans = suffix[0];
	for(int l=0;l<m;l++){
		set<int> st;
		st.insert(-1);
		st.insert(n);
		
		ll cnt = 0;
		for(int r=l;r<m;r++){
			if(pos[B[r]] != -1){
				auto it = st.lower_bound(pos[B[r]]);
				auto itR = it;
				itR--;
				
				tree.update(0, 0, n-1, (*itR)+1, pos[B[r]], -(suffix[pos[B[r]]]-suffix[*it]));
				st.insert(pos[B[r]]);
			}
			
			cnt += Y[r];
			
//			cout << l << " " << r << " -> " << cnt << " " << tree.query(0, 0, n-1, 0, n-1) << " " << tree.query(0, 0, n-1, 1, 2) << "\n";
//			cout << l << " " << r << " -> " << cnt+tree.query(0, 0, n-1, 0, n-1) << "\n";
			st2.insert({l, r, cnt+tree.query(0, 0, n-1, 0, n-1)});
			ans = max(ans, cnt+tree.query(0, 0, n-1, 0, n-1));
		}
		
		auto it = st.begin();
		while(it != st.end()){
			auto itR = it;
			itR++;
			
			if(itR == st.end()) break;
			
//			cout << l << " recovered " << (*it)+1 << " " << (*itR) << " " << suffix[*itR] << "\n";
			tree.update(0, 0, n-1, (*it)+1, *itR, suffix[*itR]);
			
			it++;
		}
	}
	
	for(auto a : st2){
		cout << a[0] << "," << a[1] << " = " << a[2] << "\n"; 
	}
	return ans;
}
