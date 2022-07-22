#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6 + 5;

string s;

struct SegTree { // index start from 0 (v)
	int tree[4*maxN][2][2], lazy[4*maxN];
	int n;
	
	void reset(){
		fill(*tree[0], *tree[4*maxN], 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void merge(int (&v)[2][2], int (&l)[2][2], int (&r)[2][2]){
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				v[x][y] = 0;
				for(int z=min(x, y);z<=max(x, y);z++){
					v[x][y] = max(v[x][y], l[x][z]+r[z][y]);
				}
			}
		}
	}
	
	void change(int (&v)[2][2]){
		int new_v[2][2];
		fill(new_v[0], new_v[2], 0);
		
		new_v[0][0] = v[1][1];
		new_v[1][1] = v[0][0];
		new_v[1][0] = v[0][1];
		new_v[0][1] = v[1][0];
		
		swap(new_v, v);
	}
	
	void push(int v){
		if(lazy[v]&1){
			change(tree[2*v+1]);
			change(tree[2*v+2]);		
		}
		
		lazy[v*2+1] += lazy[v];
		lazy[v*2+2] += lazy[v];
		lazy[v] = 0;
	}
	
	void build(int v, int l, int r){
		if(l > r) return;
		if(l == r){
			for(int x=0;x<2;x++){
				for(int y=0;y<2;y++){
					tree[v][x][y] = (min(x, y) <= (s[l] - '0') && (s[l] - '0') <= max(x, y));
				}
			}
			return;
		}
		
		int m = (l+r) >> 1;
		build(2*v+1, l, m);
		build(2*v+2, m+1, r);
		
		merge(tree[v], tree[2*v+1], tree[2*v+2]);
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			change(tree[v]);
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			merge(tree[v], tree[2*v+1], tree[2*v+2]);
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return max(tree[v][0][1], max(tree[v][0][0], tree[v][1][1]));
		}
		
		push(v);
		
		int ans[2][2];
		fill(ans[0], ans[2], 0);
		
		int curM = (curL+curR) >> 1;
		if(query(v*2+1, curL, curM, l, min(r, curM)) > 0){
			int new_ans[2][2];
			fill(new_ans[0], new_ans[2], 0);
			
			merge(new_ans, ans, tree[v*2+1]);	
			swap(new_ans, ans);
		}
		if(query(v*2+2, curM+1, curR, max(l, curM+1), r) > 0){
			int new_ans[2][2];
			fill(new_ans[0], new_ans[2], 0);
			
			merge(new_ans, ans, tree[v*2+2]);
			swap(new_ans, ans);
		}
		
		return max(ans[0][1], max(ans[0][0], ans[1][1]));
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	cin >> s;
	
	tree.reset();
	tree.build(0, 0, n-1);
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){ // update [L, R]
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			tree.update(0, 0, n-1, l, r, 1);
		} else { // query [0, N-1]
			cout << tree.query(0, 0, n-1, 0, n-1) << "\n";
		}
	}
	
    return 0;
}

