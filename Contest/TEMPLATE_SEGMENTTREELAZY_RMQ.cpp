
const int maxM = 1e6 + 5;

int tree[4*maxM], lazy[4*maxM];

void push(int v) {
    tree[2*v] += lazy[v];
    lazy[2*v] += lazy[v];
    
    tree[2*v+1] += lazy[v];
    lazy[2*v+1] += lazy[v];
    
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        tree[v] += val;
        lazy[v] += val;
    } else {
        push(v);
        
        int tm = (tl + tr) >> 1;
        update(v*2, tl, tm, l, min(r, tm), val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
	if(l > r) return inf_int;
	if(l <= tl && tr <= r){
		return tree[v];
	}
	
	push(v);
	
	int tm = (tl + tr) >> 1;
	return min(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}
