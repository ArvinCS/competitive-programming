#include <bits/stdc++.h>
#include <chrono>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define node tnode*
struct tnode {
	int prior, size, key;
	
	tnode *l, *r;
	tnode(int val) : prior(rng()), key(val), size(1), l(nullptr), r(nullptr) {
		
	}
};

int getSize(node t){
	return t?t->size:0;
}

void updateSize(node t){
	if(t) t->size=1+getSize(t->l)+getSize(t->r);
}

void split(node t, node &l, node &r, int val){
	if(!t) l = r = nullptr;
	else if(t->key <= val) split(t->r, t->r, r, val), l = t;
	else split(t->l, l, t->l, val), r = t;
	updateSize(t);
}

void merge(node &t, node l, node r){
	if(!l || !r) t = l?l:r;
	else if(l->prior>r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	updateSize(t);
}

int main(){
	return 0;
}
