#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct SegTree { // index start from 0 (v)
	ll tree[4*maxN], lazy[4*maxN];
	int n;
	void reset(int m){
		n = m;
		fill(tree, tree+4*maxN, 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	ll query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 1e18;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
};

struct Fenwick {
	int tree[maxN];
	
	void reset(int n){
		fill(tree, tree+maxN, 0);
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
};

SegTree tree;
Fenwick prefix;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> v;
	vector<int> z;
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back({a[x], x});
		z.push_back(a[x]);
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
		v.push_back({b[x], 1e9});
	}
	
	sort(z.begin(), z.end());
	z.erase(unique(z.begin(), z.end()), z.end());
	
	prefix.reset(z.size());
	
	ll ans = 0;
	for(int x=n-1;x>=0;x--){
		int idx = lower_bound(z.begin(), z.end(), a[x]) - z.begin();
		ans += prefix.query(idx-1);
		prefix.update(idx, 1);
	}
	
	sort(v.begin(), v.end());
	
	tree.reset(n);
	
	for(int x=0;x<n;x++){
		tree.update(0, 0, n, x+1, n, 1);
	}
	
	int last = -1;
	vector<int> w;
	for(int x=0;x<v.size();x++){
		if(last != v[x].first){
			while(!w.empty()){
				tree.update(0, 0, n, 0, w.back(), 1);
				w.pop_back();
			}
		}
		
		if(v[x].second < n){
			w.push_back(v[x].second);
			tree.update(0, 0, n, v[x].second+1, n, -1);
		} else {
			ans += tree.query(0, 0, n, 0, n);
		}
		last = v[x].first;
	}
	
	cout << ans << "\n";
    return 0;
}

