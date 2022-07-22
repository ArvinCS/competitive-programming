struct SegTree { // index start from 0 (v)
	vector<int> tree, lazy;
	
	int n;
	void resize(int m){
		n = m;
		tree = lazy = vector<int>(4*n+5, 0);
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = max(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return max(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};
