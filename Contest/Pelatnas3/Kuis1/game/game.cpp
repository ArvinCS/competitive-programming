#include "game.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

int N;
vector<int> A;

struct SegmentTreeSum {
	ll tree[4*maxN];
	ll lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v, int curL, int curM, int curR){
		if(lazy[v] == 0) return;
		
		tree[2*v+1] = (curM-curL+1)*lazy[v];
		lazy[2*v+1] = lazy[v];
		
		tree[2*v+2] = (curR-curM)*lazy[v];
		lazy[2*v+2] = lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, ll val){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			tree[v] = (curR-curL+1)*val;
			lazy[v] = val;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		push(v, curL, curM, curR);
		
		update(2*v+1, curL, curM, l, min(curM, r), val);
		update(2*v+2, curM+1, curR, max(l, curM+1), r, val);
		
		tree[v] = (tree[2*v+1] + tree[2*v+2]);
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r || r < curL || l > curR) return 0;
		if(curL == l && curR == r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;
		
		push(v, curL, curM, curR);
		
		return query(2*v+1, curL, curM, l, min(curM, r)) + query(2*v+2, curM+1, curR, max(l, curM+1), r);
	}
} l, r;

struct SegmentTreeGCD {
	int tree[2*maxN];
	
	void reset(){
		fill(tree, tree+2*maxN, 0);
	}
	
	void update(int pos, int val){
		pos += maxN;
		
		tree[pos] = val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = __gcd(tree[x], tree[x^1]);
		}
	}
	
	int query(int l, int r){ // [L, R)
		int ans = 0;
		
		for(l += maxN, r += maxN; l < r; l >>= 1, r >>= 1){
			if(l&1){
				ans = __gcd(ans, tree[l++]);
			}
			if(r&1){
				ans = __gcd(ans, tree[--r]);
			}
		}
		return ans;
	}
} tree;

void init(std::vector<int> B) {
	N = B.size();
	A = B;
	
	l.reset();
	r.reset();
	tree.reset();
	
	for(int x=0;x<N;x++){
		tree.update(x, A[x]);
	}
	
	int gcd = 0;
	for(int x=0;x<N;x++){
		gcd = __gcd(gcd, A[x]);
		l.update(0, 0, N-1, x, x, gcd);
	}
	
	gcd = 0;
	for(int x=N-1;x>=0;x--){
		gcd = __gcd(gcd, A[x]);
		r.update(0, 0, N-1, x, x, gcd);
	}
	return;
}

ll modify(int i, int x) {
	A[i] = x;
	tree.update(i, x);
	
	int pos = i;
	while(pos >= 0){
		int left = 0, right = pos;
		int lst = pos;
		
		int val = tree.query(pos, N);
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(tree.query(mid, N) == val){
				lst = mid;
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		r.update(0, 0, N-1, lst, pos, val);
		pos = lst-1;
	}
	
	pos = i;
	while(pos < N){ // O(log^3 N . log MAX)
		int left = pos, right = N-1;
		int lst = pos;
		
		int val = tree.query(0, pos+1);
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(tree.query(0, mid+1) == val){
				lst = mid;
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		l.update(0, 0, N-1, pos, lst, val);
		pos = lst+1;
	}
	
	ll ans = min(r.query(0, 0, N-1, 1, N-1), l.query(0, 0, N-1, 0, N-2));
	
	auto cost = [&](int pos) -> ll {
		return r.query(0, 0, N-1, 1, min(N-1, pos))+l.query(0, 0, N-1, max(0, pos), N-2);
	};
	
	int left = 0, right = N-2;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		ll l = cost(mid), r = cost(mid+1);
		ans = min(ans, min(l, r));
		
		if(l > r){
			left = mid+1;	
		} else if(l == r){
			if(cost(left) > cost(right)){
				left = mid+1;
			} else {
				right = mid-1;
			}
		} else if(l < r){
			right = mid-1;
		}
	}
	
	return tree.query(0, N) + ans;
}
