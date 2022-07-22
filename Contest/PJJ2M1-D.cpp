#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Vertex {
	int l, r, val = 0, lazy = 0;
	Vertex *left, *right;
	
	int query(){
		if(lazy&1){
			val = (r-l+1)-val;
		}
		return val;
	}
	
	Vertex(int l, int r) : l(l), r(r), val(0), lazy(0), left(nullptr), right(nullptr){
		
	}
	
	Vertex(int l, int r, Vertex *left, Vertex *right) : l(l), r(r), val(0), lazy(0), left(left), right(right) {
		if(left) val += left->val;
		if(right) val += right->val;
	}
	
	Vertex(int l, int r, Vertex *left, Vertex *right, int lazy) : l(l), r(r), val(0), lazy(lazy), left(left), right(right) {
		if(left) val += left->val;
		if(right) val += right->val;
	}
};

struct SegTree {
	Vertex* build(int l, int r){
		if(l == r) return new Vertex(l, r);
		
		int m = (l+r) >> 1;
		return new Vertex(l, r, build(l, m), build(m+1, r));
	}
	
	void push(Vertex *v){
		if(v->lazy % 2 == 1){
			if(v->left){
				int val = v->left->val;
				v->left = new Vertex(v->left->l, v->left->r, v->left->left, v->left->right, v->left->lazy+1);
				v->left->val = (v->left->r - v->left->l + 1) - val;
			}
			
			if(v->right){
				int val = v->right->val;
				v->right = new Vertex(v->right->l, v->right->r, v->right->left, v->right->right, v->right->lazy+1);
				v->right->val = (v->right->r - v->right->l + 1) - val;
			}
		}
		
		v->lazy = 0;
	}
	
	Vertex* update(Vertex *v, int curL, int curR, int l, int r, int val){
		if(curL > r || curR < l || l > r) return v;
		if(!v) return v;
			
		if(curL == l && curR == r){
			Vertex *tmp = new Vertex(curL, curR, v->left, v->right, v->lazy + val);
			tmp->val = (curR-curL+1)-v->val;
			return tmp;
		} else {
			int curM = (curL+curR) >> 1;
			
			Vertex *tmp = new Vertex(curL, curR, v->left, v->right, v->lazy);
			push(tmp);
			
			if(curL <= curM){
				tmp->left = update(tmp->left, curL, curM, l, min(r, curM), val);
			}
			if(curM+1 <= curR){
				tmp->right = update(tmp->right, curM+1, curR, max(l, curM+1), r, val);
			}
			
			tmp->val = 0;
			if(tmp->left) tmp->val += tmp->left->val;
			if(tmp->right) tmp->val += tmp->right->val;
			
			return tmp;
		}
	}
	
	pair<int, Vertex*> query(Vertex *v, int curL, int curR, int l, int r){
		if(curL > r || curR < l || l > r) return {0, v};
		
		if(curL == l && curR == r){
			return {v->val, v};
		} else {
			int curM = (curL+curR) >> 1;
			
			Vertex* tmp = new Vertex(curL, curR, v->left, v->right, v->lazy);
			
			push(tmp);

			ll ans = 0;
			
			if(curL <= curM){
				pair<int, Vertex*> p = query(tmp->left, curL, curM, l, min(r, curM));
				ans += p.first;
				tmp->left = p.second;
			}
			if(curM+1 <= curR){
				pair<int, Vertex*> p = query(tmp->right, curM+1, curR, max(l, curM+1), r);
				ans += p.first;
				tmp->right = p.second;
			}
			
			tmp->val = 0;
			if(tmp->left) tmp->val += tmp->left->val;
			if(tmp->right) tmp->val += tmp->right->val;
			
			return {ans, tmp};
		}
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<Vertex*> v;
	v.push_back(tree.build(0, n*m-1));
	
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		
		if(t == 1){ // 1 i j
			int x, y;
			cin >> x >> y;
			
			x--; y--;
			
			pair<int, Vertex*> p = tree.query(v.back(), 0, n*m-1, x*m+y, x*m+y);
			if(p.first == 0){
				v.push_back(tree.update(p.second, 0, n*m-1, x*m+y, x*m+y, 1));
			} else {
				v.push_back(p.second);
			}
		} else if(t == 2){ // 2 i j
			int x, y;
			cin >> x >> y;
			
			x--; y--;
			
			pair<int, Vertex*> p = tree.query(v.back(), 0, n*m-1, x*m+y, x*m+y);
			if(p.first == 1){
				v.push_back(tree.update(p.second, 0, n*m-1, x*m+y, x*m+y, 1));
			} else {
				v.push_back(p.second);
			}
		} else if(t == 3){ // 3 i
			int x;
			cin >> x;
			
			x--;
			v.push_back(tree.update(v.back(), 0, n*m-1, x*m, x*m+m-1, 1));
		} else if(t == 4){ // 4 k
			int k;
			cin >> k;
			
			v.push_back(v[k]);
		}
		
		cout << v.back()->val << "\n";
	}
	
    return 0;
}

