#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 4e5 + 5;

struct SegTree {
	int tree[4*maxN], lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v){
		if(lazy[v] == 0) return;
		
		tree[v*2+1] = max(tree[2*v+1], lazy[v]);
		lazy[v*2+1] = max(lazy[2*v+1], lazy[v]);
		
		tree[v*2+2] = max(tree[2*v+2], lazy[v]);
		lazy[v*2+2] = max(lazy[2*v+2], lazy[v]);
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(curL > curR || l > r) return;
		if(curL == l && r == curR){
			if(tree[v] < val){
				tree[v] = val;
				lazy[v] = val;
			}
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
} tree;

//void solve(int k, int l, int r, int )
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v;
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		v.push_back(p[x].first);
		v.push_back(p[x].second);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		p[x].first = lower_bound(v.begin(), v.end(), p[x].first) - v.begin();
		p[x].second = lower_bound(v.begin(), v.end(), p[x].second) - v.begin();
	}
	
	int q;
	cin >> q;
	
//	assert(q <= 5000);
	
	int cnt = 1;
	for(int i=1;i<=q;i++){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		
		int ans = 1;
		for(int x=l;x<=r;x++){
//			cout << x << " -> " << p[x].first << " " 
			if(tree.query(0, 0, v.size()-1, p[x].first, p[x].second) == 1){
				tree.reset();
				ans++;
			}
			tree.update(0, 0, v.size()-1, p[x].first, p[x].second, 1);
		}
		tree.reset();
		
		cout << ans << "\n";
	}
    return 0;
}

