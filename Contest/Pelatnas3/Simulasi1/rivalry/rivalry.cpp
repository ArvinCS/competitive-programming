#include "rivalry.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

//struct Node {
//	ll val = 0;
//	Node *l, *r;
//	
//	Node() : val(0), l(nullptr), r(nullptr) {
//			
//	}
//};

//struct SegmentTree {
//	void update(Node* &v, ll curL, ll curR, ll pos, int val){
//		if(curL > curR) return;
//		if(v == nullptr) v = new Node();
//		if(curL == curR && curL == pos){
//			v->val += val;
//			return;
//		}
//		
//		ll curM = (curL+curR) >> 1;
//		if(pos <= curM){
//			update(v->l, curL, curM, pos, val);
//		} else {
//			update(v->r, curM+1, curR, pos, val);
//		}
//		
//		v->val = 0;
//		if(v->l){
//			v->val += v->l->val;
//		}
//		if(v->r){
//			v->val += v->r->val;
//		}
//	}
//	
//	ll query(Node* &v, ll curL, ll curR, ll l, ll r) {
//		if(curL > curR || l > r) return 0;
//		if(!v) return 0;
//		if(curL == l && curR == r){
//			return v->val;
//		}
//		
//		ll curM = (curL+curR) >> 1;
//		return query(v->l, curL, curM, l, min(curM, r)) + query(v->r, curM+1, curR, max(l, curM+1), r);
//	}
//} tree;

std::vector<long long> find_final_scores(int N, std::vector<int> A, std::vector<int> B) {
	int M = A.size();
	vector<ll> ans(N, 1e18);
	ans[0] = 0;
	
//	Node *n = new Node();
	
//	auto solve = [&](int bound, int x) -> ll { // O(log^2Max)
//		ll left = ans[bound-1], right = 1e16;
//		ll best = 1e18;
//		
//		while(left <= right){
//			ll mid = (left+right) >> 1;
//			
//			int cur = x+1;
//			if(x+1 <= tree.query(n, 0, 1e18, 0, mid)){
//				right = mid-1;
//				best = mid;
//			} else {
//				left = mid+1;
//			}
//		}
//		
//		return best;
//	};
//	
//	for(int y=0;y<M;y++){
//		tree.update(n, 0, 1e18, A[y]+B[y], 1);
//	}
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	for(int y=0;y<M;y++){
		pq.push({A[y]+B[y], y});
	}
	
	int cnt[M];
	fill(cnt, cnt+M, 0);
	
	ll mx = 0;
	for(int x=1;x<N;x++){ // O(NlogN)
		if(x == 1){
			pair<ll, ll> tmp = pq.top();
			pq.pop();
			
			pair<ll, ll> tmp2 = pq.top();
			pq.pop();
			
			mx = tmp2.first;
			
			ans[x] = mx;
			
			cnt[tmp.second]++;
			cnt[tmp2.second]++;
			pq.push({A[tmp.second]*1ll*(cnt[tmp.second]+1) + B[tmp.second] + ans[cnt[tmp.second]], tmp.second});
			pq.push({A[tmp2.second]*1ll*(cnt[tmp2.second]+1) + B[tmp2.second] + ans[cnt[tmp2.second]], tmp2.second});
		} else {
			pair<ll, ll> tmp = pq.top();
			pq.pop();
			
			mx = tmp.first;
			
			ans[x] = mx;
			
			cnt[tmp.second]++;
			pq.push({A[tmp.second]*1ll*(cnt[tmp.second]+1) + B[tmp.second] + ans[cnt[tmp.second]], tmp.second});
		}
	}
	
	return ans;
}
