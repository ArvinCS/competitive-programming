#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

int n;

struct Node {
	Node *l, *r;
	int val;
	
	Node() : l(nullptr), r(nullptr), val(0){
		
	}
};
	
struct FenwickTree { // index start from 0 (v)
	map<int, int> tree;
	
	void update(int pos, int val, bool rev){
		pos++;
		if(rev) pos = n+1-pos;
		
		while(pos < n+1){
			tree[pos] = max(tree[pos], val);
			pos += pos&(-pos);
		}
	}
	
	int query(int pos, bool rev){
		pos++;
		if(rev) pos = n+1-pos;
		
		int ans = 0;
		while(pos > 0){
			ans = max(ans, tree[pos]);
			pos -= pos&(-pos);
		}
		return ans;
	}
};

struct RangeTree {
	FenwickTree tree[2*maxN];
	
	void reset(){
		
	}
	
	void update(int pos, int pos2, int val, bool rev){
		pos += n;
		
		for(int x=pos;x>=1;x>>=1){
			tree[x].update(pos2, val, rev);
		}
	}
	
	int query(int l, int r, int pos, bool rev){
		int ans = 0;
		for(l += n, r += n; l<r; l>>=1, r>>=1){
			if(l&1){
				ans = max(ans, tree[l].query(pos, rev));
				l++;
			}
			if(r&1){
				--r;
				ans = max(ans, tree[r].query(pos, rev));
			}
		}
		
		return ans;
	}
};

RangeTree tree, tree2;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll m;
	cin >> n >> m;
	
	ll t[n];
	for(int x=0;x<n;x++){
		cin >> t[x];
	}
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	// case if al <= ar (ar >= al)
	// if (tr-tl)*v >= (ar-al)
	// - val_r = max(val_r, val_l+1)
	// 
	// (tr-tl)*v >= (ar-al)
	// tr*v - tl*v >= ar - al
	// al - tl*v >= ar - tr*v
	// 
	// case if al > ar (ar < al)
	// if (tr-tl)*v >= (al-ar)
	// - val_r = max(val_r, val_l+1)
	// 
	// (tr-tl)*v >= (al-ar)
	// tr*v - tl*v >= al - ar
	// - al - tl*v >= - ar - tr*v
	// -(al+tl*v) >= -(ar+tr*v)
	// al+tl*v <= ar+tr*v
	// 
	
	vector<ll> v, w, z;
	for(int x=0;x<n;x++){
		v.push_back(a[x]-t[x]*m);
		w.push_back(a[x]+t[x]*m);
		z.push_back(a[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	
	sort(z.begin(), z.end());
	z.erase(unique(z.begin(), z.end()), z.end());
	
	int l[n], r[n], id[n];
	for(int x=0;x<n;x++){
		l[x] = lower_bound(v.begin(), v.end(), a[x]-t[x]*m) - v.begin();
		r[x] = lower_bound(w.begin(), w.end(), a[x]+t[x]*m) - w.begin();
		id[x] = lower_bound(z.begin(), z.end(), a[x]) - z.begin();
	}
	
	tree.reset();
	tree2.reset();
	
	int ans = 0;
	for(int x=0;x<n;x++){
		int mx = 0;
		mx = max(mx, tree.query(0, id[x]+1, l[x], true));
		mx = max(mx, tree2.query(id[x]+1, z.size(), r[x], false));
		
		tree.update(id[x], l[x], mx+(t[x]*m >= a[x]?1:0), true);
		tree2.update(id[x], r[x], mx+(t[x]*m >= a[x]?1:0), false);
		
		ans = max(ans, mx+(t[x]*m >= a[x]?1:0));
	}
	
	cout << ans << "\n";
    return 0;
}
