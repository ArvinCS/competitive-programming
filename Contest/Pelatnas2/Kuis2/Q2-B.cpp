#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//struct Node {
//	ll key;
//	ll val;
//	pair<ll, ll> mx;
//	ll prior;
//	ll lazy;
//	Node *l, *r;
//	
//	Node() : key(key), val(key), lazy(0), mx({key, key}), prior(rng()), l(nullptr), r(nullptr){
//		
//	}
//};
//
//void push(Node t){
//	if(t.l != NULL){
//		t.l->val += t.l->key*t.lazy;
//		t.l->lazy += t.lazy;
//	}
//	if(t.r != NULL){
//		t.r->val += t.r->key*t.lazy;
//		t.r->lazy += t.lazy;
//	}
//	
//	t.lazy = 0;
//}
//
//void split(Node t, Node *l, Node *r, int val){
//	push(t);
//	
//	if(t.key <= val){
////		Node tmp = t.r;
//		if(t.r != nullptr) split(t.r, t.r, r, val);
//		l = t;
//	} else {
//		if(t.l != nullptr) split(t.l, l, t.l, val);
//		r = t;
//	}
//	
//	t->mx = max(t->mx, t->val);
//	if(t->l) t->mx = max(t->mx, t->l->mx);
//	if(t->r) t->mx = max(t->mx, t->r->mx);
//}
//
//void merge(Node &t, Node l, Node r){
//	if(!l || !r){
//		t = (l ? l : r);
//		return;
//	}
//	
//	push(l); push(r);
//	
//	if(l.prior > r.prior) merge(l->r, l->r, r), t = l;
//	else merge(r->l, l, r->l), t = r;
//	
//	t->mx = max(t->mx, t->val);
//	if(t->l) t->mx = max(t->mx, t->l->mx);
//	if(t->r) t->mx = max(t->mx, t->r->mx);
//}

const int maxN = 2e5;

struct SegmentTree {
	pair<ll, ll> tree[4*maxN];
	ll cnt[4*maxN], lazy[4*maxN];
	
	void build(){
		fill(tree, tree+4*maxN, make_pair(-1e18, 0));
		fill(cnt, cnt+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v){
		tree[2*v+1].first += lazy[v]*tree[2*v+2].second;
		lazy[2*v+1] += lazy[v];
		
		tree[2*v+2].first += lazy[v]*tree[2*v+2].second;
		lazy[2*v+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update_val(int v, int curL, int curR, int pos, ll val){
		if(curL > curR) return;
		
		if(curL == curR){
			tree[v] = {cnt[v]*val, val};
			return;
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		
		if(pos <= curM){
			update_val(2*v+1, curL, curM, pos, val);
		} else {
			update_val(2*v+2, curM+1, curR, pos, val);
		}
		
		tree[v] = max(tree[2*v+1], tree[2*v+2]);
	}
	
	void update_cnt(int v, int curL, int curR, int l, int r, ll val){
		if(curL > curR || l > r) return;
				
		if(curL == l && curR == r){
			tree[v].first += val*tree[v].second;
			cnt[v] += val;
			lazy[v] += val;
			return;
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		
		update_cnt(2*v+1, curL, curM, l, min(curM, r), val);
		update_cnt(2*v+2, curM+1, curR, max(l, curM+1), r, val);
		
		tree[v] = max(tree[2*v+1], tree[2*v+2]);
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	sort(p, p+n);
	
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		v.push_back({p[x].first, x});
		v.push_back({p[x].second, x});
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	
	vector<pair<ll, ll>> order;
	ll ans = 0;
	for(int x=0;x<v.size();x++){
		order.push_back({p[v[x].second].first, v[x].first*(n-x)});
	}
	
	for(int x=0;x<order.size();x++){
		ans = max(ans, order[x].second+order[x].first*(n-x));
	}
	cout << ans << "\n";
}
