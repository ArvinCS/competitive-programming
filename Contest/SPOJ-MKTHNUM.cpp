#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
struct Vertex {
	Vertex *left, *right;
	int val;
	
	Vertex(int val) : left(nullptr), right(nullptr), val(val) {
	}
	
	Vertex(Vertex *left, Vertex *right) : left(left), right(right), val(0){
		if(left) val += left->val;
		if(right) val += right->val;
	}
};

struct SegTree {
	Vertex* build(int l, int r){
		if(l == r) return new Vertex(0);
		
		int m = (l+r) >> 1;
		return new Vertex(build(l, m), build(m+1, r));
	}
	
	Vertex* update(Vertex *v, int l, int r, int pos, int val){
		int mid = (l + r) >> 1;
		
		if(l == r){
			return new Vertex(val);
		} else if(pos <= mid){
			return new Vertex(update(v->left, l, mid, pos, val), v->right);
		} else {
			return new Vertex(v->left, update(v->right, mid+1, r, pos, val));
		}
	}
	
	int query(Vertex *now, Vertex *prev, int l, int r, int pos){
		if(l == r) return l;
		
		int mid = (l+r) >> 1;
		int leftCnt = (now->left->val - prev->left->val);
		if(pos <= leftCnt){
			return query(now->left, prev->left, l, mid, pos);
		} else {
			return query(now->right, prev->right, mid+1, r, pos-leftCnt);
		}
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> v;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back({a[x], x});
	}
	
	int l[m], r[m], k[m];
	for(int x=0;x<m;x++){
		cin >> l[x] >> r[x] >> k[x];
	}
	
	sort(v.begin(), v.end());
	
	vector<Vertex*> roots;
	roots.push_back(tree.build(0, n-1));
	for(int x=0;x<n;x++){
		roots.push_back(tree.update(roots.back(), 0, n-1, lower_bound(v.begin(), v.end(), make_pair(a[x], -1)) - v.begin(), 1));
	}
	
	for(int x=0;x<m;x++){
		int pos = tree.query(roots[r[x]], roots[l[x]-1], 0, n-1, k[x]);
		
		cout << v[pos].first << "\n";
	}
    return 0;
}
