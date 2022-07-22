#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;

struct SegmentTree {
	int tree[4*maxN];
	int left_state[4*maxN], right_state[4*maxN];
	int left_last[4*maxN], right_last[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(left_state, left_state+4*maxN, 0);
		fill(right_state, right_state+4*maxN, 0);
		fill(left_last, left_last+4*maxN, 0);
		fill(right_last, right_last+4*maxN, 0);
	}
	
	void merge(int v){
		tree[v] = tree[2*v+1]+tree[2*v+2];
		if(left_state[2*v+2] == 5){
			if(left_last[2*v+2] == 7){
				if(right_state[2*v+1]&5){
					if(right_last[2*v+1] == 7){
						tree[v]--;
					} else {
						int left_cnt = __builtin_popcount(right_state[2*v+1]);
						if(right_state[2*v+1]&2) left_cnt = 1;
						
						tree[v] -= left_cnt;
					}
				}
			} else {
				if(right_state[2*v+1]&1){
					tree[v]--;
				}
				if(right_state[2*v+1]&4){
					tree[v]--;
				}
			}
		} else if(left_state[2*v+2] != 0){
			if(right_last[2*v+1] == 7){
				if(right_state[2*v+1]&left_state[2*v+2]){
					tree[v]--;
				}
			} else {
				if(left_last[2*v+2] == 7){
					if(right_state[2*v+1]&left_state[2*v+2]){
						int left_cnt =  __builtin_popcount(right_state[2*v+1]);
						if(right_state[2*v+1]&2) left_cnt = 1;
						
						tree[v] -= left_cnt;
					}
				} else {
					if(right_state[2*v+1]&left_state[2*v+2]){
						tree[v]--;
					}
				}
			}
		}
		
		if(left_last[2*v+1] != 5){
			left_last[v] = left_last[2*v+1];	
		} else {
			left_last[v] = left_last[2*v+2];
		}
		
		if(right_last[2*v+2] != 5){
			right_last[v] = right_last[2*v+2];	
		} else {
			right_last[v] = right_last[2*v+1];
		}
		
		left_state[v] = left_state[2*v+1];
		right_state[v] = right_state[2*v+2];
	}
	
	void build(int v, int l, int r, int state[]){
		if(l > r) return;
		if(l == r){
			tree[v] = ((state[l]&2) != 0 ? 1 : __builtin_popcount(state[l]));
			left_state[v] = right_state[v] = state[l];
			left_last[v] = right_last[v] = state[l];
			return;
		}
		
		int m = (l+r) >> 1;
		
		build(2*v+1, l, m, state);
		build(2*v+2, m+1, r, state);
		
		merge(v);
	}
	
	void query(int v, int curL, int curR, int l, int r, int &cnt, int &state, int &last){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			cnt += tree[v];
			
			if(left_state[v] == 5){
				if(left_last[v] == 7){
					if(state&5){
						if(last == 7){
							cnt--;
						} else {
							int left_cnt = __builtin_popcount(state);
							if(state&2) left_cnt = 1;
							
							cnt -= left_cnt;
						}
					}
				} else {
					if(state&1){
						cnt--;
					}
					if(state&4){
						cnt--;
					}
				}
			} else if(left_state[v] != 0){
				if(last == 7){
					if(state&left_state[v]){
						cnt--;
					}
				} else {
					if(left_last[v] == 7){
						if(state&left_state[v]){
							int left_cnt = __builtin_popcount(state);
							if(state&2) left_cnt = 1;
							
							cnt -= left_cnt;
						}
					} else {
						if(state&left_state[v]){
							cnt--;
						}
					}
				}
			}
			
			if(right_last[v] != 5) last = right_last[v];
			state = right_state[v];
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		query(2*v+1, curL, curM, l, min(curM, r), cnt, state, last);
		query(2*v+2, curM+1, curR, max(curM+1, l), r, cnt, state, last);
	}
};

SegmentTree tree;

int main(){ // can support update operation too
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int state[n];
	fill(state, state+n, 0);
	
	for(int i=0;i<3;i++){
		for(int x=0;x<n;x++){
			char c;
			cin >> c;
			
			if(c == '1'){
				state[x] |= (1 << i);
			}
		}
	}
	
	tree.reset();
	tree.build(0, 0, n-1, state);
	
	int q;
	cin >> q;
	
	while(q--){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		
		int ans = 0, state = 0, last = 0;
		tree.query(0, 0, n-1, l, r, ans, state, last);
		
		cout << ans << "\n";
	}
    return 0;
}

