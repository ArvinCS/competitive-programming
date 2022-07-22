#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define tnode TNode*
struct TNode {
	ll prior;
	int val, sz;
	TNode *l, *r;
	
	TNode (int val) : prior(rng()), sz(1), val(val), l(nullptr), r(nullptr){
		
	}
};

void updateSize(tnode t){
	if(!t) return;
	
	t->sz = 1;
	if(t->l) t->sz += t->l->sz;
	if(t->r) t->sz += t->r->sz;
}

void split(tnode t, tnode &l, tnode &r, int x){
	if(!t) l=r=nullptr;
	else if(t->val <= x) split(t, t->l, r, x), l = t;
	else split(t, l, t->r, x), r = t;
	updateSize(t);
}

void merge(tnode &t, tnode l, tnode r){
	if(!l || !r) t = (l ? l : r);
	else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	updateSize(t);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q, x;
	cin >> n >> q >> x;
	
	tnode t[n];
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		t[x] = new TNode(val);
	}
	
	tnode root = t[0];
	for(int x=1;x<n;x++){
		tnode newRoot;
		merge(newRoot, root, t[x]);
		root = newRoot;
	}
	
	for(int i=1;i<=q;i++){
		int c, l, r;
		cin >> c >> l >> r;
		
		
	}
    return 0;
}

