#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = (1 << 18);

#define tnode TNode*
struct TNode {
	TNode *l, *r;
	ll sum;
	int lazy;
	
	TNode() : lazy(0), sum(0), l(nullptr), r(nullptr){
	}
};

struct SegmentTree{
	void updateSum(tnode &t){
		t->sum = 0;
		if(t->l) t->sum += t->l->sum;
		if(t->r) t->sum += t->r->sum;
	}
	
	tnode build(int l, int r, int a[]){
		if(l > r) return new TNode();
		if(l == r){
			tnode node = new TNode();
			node->sum = a[l];
			return node;
		}
		
		int m = (l+r) >> 1;
		
		tnode node = new TNode();
		
		node->l = build(l, m, a);
		node->r = build(m+1, r, a);

		updateSum(node);
		
		return node;
	}
	
	void push(tnode &node){
		if(node->l) node->l->lazy ^= node->lazy;
		if(node->r) node->r->lazy ^= node->lazy;
		node->lazy = 0;
	}
	
	void check(tnode &node, int i){
		if(node->lazy&(1 << i)){
			swap(node->l, node->r);
			node->lazy ^= (1 << i);
		}
	}
	
	void update(tnode &node, int curL, int curR, int l, int r, int i, int val){
		if(curL > curR || l > r) return;
		
		check(node, i);
		push(node);
		
		if(curL == l && curR == r){
			node->lazy ^= val;
			check(node, i);
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		update(node->l, curL, curM, l, min(curM, r), i-1, val);
		update(node->r, curM+1, curR, max(curM+1, l), r, i-1, val);
	}
	
	void mod(tnode &node, int curL, int curR, int pos, int val){
		if(curL > curR) return;
		
		int i = log2(curR-curL+1);
		if(curR-curL+1 == (1 << i)) check(node, i);
		push(node);
		
		if(curL == curR){
			node->sum = val;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		if(pos <= curM){
			mod(node->l, curL, curM, pos, val);
		} else {
			mod(node->r, curM+1, curR, pos, val);
		}
		
		updateSum(node);
	}
	
	ll query(tnode &node, int curL, int curR, int l, int r){
		if(curL > curR || l > r || !node) return 0;
		
		int i = log2(curR-curL+1);
		if(curR-curL+1 == (1 << i)) check(node, i);
		push(node);
		
		if(curL == l && curR == r){
			return node->sum;
		}
		
		int curM = (curL+curR) >> 1;
		
		return query(node->l, curL, curM, l, min(r, curM)) + query(node->r, curM+1, curR, max(l, curM+1), r);
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int m = (1 << n);
	
	int a[m];
	for(int x=0;x<m;x++){
		cin >> a[x];
	}
	
	tnode node = tree.build(0, m-1, a);
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos, val;
			cin >> pos >> val;
			
			pos--;
			tree.mod(node, 0, m-1, pos, val);
		} else if(t == 2){
			int k;
			cin >> k;
			
			int state = (1 << (k+1))-1;
			tree.update(node, 0, m-1, 0, m-1, n, state);
		} else if(t == 3){
			int k;
			cin >> k;
			
			int state = (1 << (k+1));
			tree.update(node, 0, m-1, 0, m-1, n, state);
		} else if(t == 4){
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			cout << tree.query(node, 0, m-1, l, r) << "\n";
		}
	}
    return 0;
}

