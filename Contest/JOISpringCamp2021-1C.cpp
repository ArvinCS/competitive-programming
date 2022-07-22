#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Vertex {
	int l, r;
	ll val = 0, lazy = 0;
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
	
	Vertex(int l, int r, Vertex *left, Vertex *right, ll lazy) : l(l), r(r), val(0), lazy(lazy), left(left), right(right) {
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
		if(v->lazy == 0) return;
		
		if(v->left){
			v->left = new Vertex(v->left->l, v->left->r, v->left->left, v->left->right, v->left->lazy+v->lazy);
			v->left->val += (v->left->r - v->left->l + 1) * v->lazy;
		}
		
		if(v->right){
			v->right = new Vertex(v->right->l, v->right->r, v->right->left, v->right->right, v->right->lazy+v->lazy);
			v->right->val += (v->right->r - v->right->l + 1) * v->lazy;
		}
		
		v->lazy = 0;
	}
	
	Vertex* update(Vertex *v, int curL, int curR, int l, int r, ll val){
		if(curL > r || curR < l || l > r) return v;
		if(!v) return v;
			
		if(curL == l && curR == r){
			Vertex *tmp = new Vertex(curL, curR, v->left, v->right, v->lazy + val);
			tmp->val = (curR-curL+1) * val;
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
	
	pair<ll, Vertex*> query(Vertex *v, int curL, int curR, int pos){
		if(curL == curR){
			return {v->val, v};
		} else {
			int curM = (curL+curR) >> 1;
			
			Vertex* tmp = new Vertex(curL, curR, v->left, v->right, v->lazy);
			
			push(tmp);

			ll ans = 0;
			
			if(pos <= curM){
				pair<int, Vertex*> p = query(tmp->left, curL, curM, pos);
				ans = p.first;
				tmp->left = p.second;
			} else {
				pair<int, Vertex*> p = query(tmp->right, curM+1, curR, pos);
				ans = p.first;
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
	
	vector<pair<int, Vertex*>> join;
	join.push_back({-1, tree.build(0, n-1)});
	
	
		
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){ // Join
			int l, r, c, k;
			cin >> l >> r >> c >> k;
			
			l--; r--;
			
			join.push_back({c, tree.update(join.back().second, 0, n-1, l, r, k)});
		} else if(t == 2){ // Leave
			int l, r, k;
			cin >> l >> r >> k;
			
			l--; r--;
			leave.push_back({-1, tree.update(leave.back().second, 0, n-1, l, r, k)});
		} else if(t == 3){
			int a, b;
			cin >> a >> b;
			
			a--;
			
			int left = 1, right = join.size()-1;
			int pos = -1;
			
			while(left <= right){
				int mid = (left+right) >> 1;
				
				cout << a << " " << mid << " -> " << tree.query(join[mid].second, 0, n-1, a).first << "\n";
				if(tree.query(join[mid].second, 0, n-1, a).first >= b){
					pos = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			if(pos != -1){
				cout << join[pos].first << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}
	
    return 0;
}

