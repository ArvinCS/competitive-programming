#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 4e5 + 5;

struct Node {
	Node *l, *r;
	ll val;
	
	Node() : l(nullptr), r(nullptr), val(-1){
		
	}
};
	
struct SegmentTree { // index start from 0 (v)
	ll getVal(Node* &n){
		if(n == NULL) return -1;
		return n->val;
	}
	
	void update(Node* &n, int curL, int curR, int pos, ll val){
		if(n == NULL) n = new Node();
		if(curL > curR) return;
		if(curL == curR && curL == pos){
			n->val = max(getVal(n), val);
		} else {
			int curM = (curL+curR) >> 1;
			
			if(pos <= curM) update(n->l, curL, curM, pos, val);
			else update(n->r, curM+1, curR, pos, val);
			
			n->val = max(getVal(n->l), getVal(n->r));
		}
	}
	
	ll query(Node* &n, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return -1;
		if(n == NULL) return -1;
		if(l <= curL && curR <= r){
			return n->val;
		}
		
		int curM = (curL+curR) >> 1;
		return max(query(n->l, curL, curM, l, min(r, curM)), query(n->r, curM+1, curR, max(l, curM+1), r));
	}
};
 
SegmentTree segtree;

vector<pair<int, int>> vX[maxN];
Node* tree[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<ll> w;
	array<ll, 3> p[n];
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			cin >> p[x][y];
			w.push_back(p[x][y]);
		}
	}
	
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			p[x][y] = lower_bound(w.begin(), w.end(), p[x][y]) - w.begin();
		}
	}
	
	for(int x=0;x<n;x++){
		vX[p[x][0]].push_back({p[x][1], p[x][2]});
	}
	
	Node *mx = nullptr;
	Node *mx2 = nullptr;
	
	ll ans = -1;
	for(int x=0;x<maxN;x++){
		sort(vX[x].rbegin(), vX[x].rend());
		
		ll val = 0;
		int curY = maxN;
		for(auto p : vX[x]){
			while(curY > p.first+1){
				curY--;
				val = max(val, segtree.query(tree[curY], 0, maxN-1, p.second+1, maxN-1));
			}
			if(val > 0) ans = max(ans, w[x]+val);
		}
		
		for(auto p : vX[x]){
			int val = segtree.query(mx, 0, maxN-1, 0, p.first-1);
			if(val > p.second){
				segtree.update(tree[p.first], 0, maxN-1, val, w[p.first]+w[val]);
//				tree[p.first].update(p.first, val, w[p.first]+w[val]);
			}
			
			val = segtree.query(mx2, 0, maxN-1, 0, p.second-1);
			if(val > p.first){
				segtree.update(tree[val], 0, maxN-1, p.second, w[p.first]+w[val]);
//				tree.update(val, p.second, w[p.second]+w[val]);
			}
			
			segtree.update(mx, 0, maxN-1, p.first, p.second);
			segtree.update(mx2, 0, maxN-1, p.second, p.first);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

