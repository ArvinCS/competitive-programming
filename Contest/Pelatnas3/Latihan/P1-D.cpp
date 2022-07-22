#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rnd(ll l, ll r) { return (l + (rng() % (r - l + 1))); }

struct TNode {
	int sz, val, sum;
	ll prior;
	bool flip;
	TNode *l, *r;
	
	TNode() : sz(1), flip(false), val(1), sum(1), prior(rnd(-1e18, 1e18)), l(nullptr), r(nullptr){
		
	}
};

typedef TNode* tnode;

int getSize(tnode t){
	if(!t) return 0;
	return t->sz;
}

int getPrior(tnode t){
	if(!t) return 0;
	return t->prior;
}

void push(tnode t){
	if(!t || !t->flip) return;
	if(t->l) t->l->flip ^= t->flip;
	if(t->r) t->r->flip ^= t->flip;
	if(t->flip) swap(t->l, t->r);
	t->flip = false;
}

void update(tnode t){
	if(!t) return;
	
	t->sz = 1;
	t->sum = t->val;
	
	if(t->l){
		t->sz += t->l->sz;
		t->sum += t->l->sum;
	}
	if(t->r){
		t->sz += t->r->sz;
		t->sum += t->r->sum;
	}
}

void split(tnode t, tnode &l, tnode &r, int pos, int add = 0){
	if(!t){
		l = r = nullptr;
		return;
	}
	
	push(t);
	
	int cur_key = add + getSize(t->l);
	if(cur_key <= pos){
		split(t->r, t->r, r, pos, cur_key+1);
		l = t;
	} else {
		split(t->l, l, t->l, pos, add);
		r = t;
	}
	
	update(t);
}

void merge(tnode &t, tnode l, tnode r){
	push(l); push(r);
	
	if(!l || !r) t = (!l ? r : l);
	else if(getPrior(l) > getPrior(r)) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	
	update(t);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	tnode root = nullptr;
	for(int x=0;x<n;x++){
		tnode node = new TNode();
		tnode l;
		tnode r;
		split(root, l, r, x-1);
		
		tnode tmp;
		merge(tmp, l, node);
		merge(root, tmp, r);
	}
	
	auto query = [&](int left, int right) -> int {
		tnode l;
		tnode r;
		
		split(root, l, r, right);
		
		tnode l1;
		tnode l2;
		split(l, l1, l2, left-1);
		
		int ans = (l2 ? l2->sum : 0);
		
		merge(l, l1, l2);
		merge(root, l, r);
		
		return ans;
	};
	
	auto add = [&](int pos, int val) -> void {
		tnode l;
		tnode r;
		
		split(root, l, r, pos);
		
		tnode l1;
		tnode l2;
		split(l, l1, l2, pos-1);
		
		if(l2) l2->val += val;
		
		merge(l, l1, l2);
		merge(root, l, r);
	};
	
	auto remove = [&](int left, int right) -> tnode {
		tnode l, r;
		
		split(root, l, r, right);
		
		tnode l1;
		tnode l2;
		split(l, l1, l2, left-1);
		
		merge(root, l1, r);
		
		return l2;
	};
	
	auto move = [&](int left, int right, int pos) -> void {
		tnode nw = remove(left, right);
		if(!nw) return;
		
		nw->flip ^= 1;
		
		tnode l;
		tnode r;
		split(root, l, r, pos-(right-left+1));
		
		tnode tmp;
		merge(tmp, l, nw);
		merge(root, tmp, r);
	};
	
	int len = n;
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int p;
			cin >> p;
			
			p--;
			
			int mn = min(p+1, len-(p+1));
			
			for(int x=0;x<mn;x++){
				int val = query(p-x, p-x);
				add(p+1+x, val);
			}
			
			if(p >= mn){
				move(0, p-mn, p+mn);
			}
			remove(0, mn-1);
			len -= mn;
			
			assert(getSize(root) == len);
		} else {
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			
			cout << query(l, r) << "\n";
		}
	}
	
    return 0;
}

