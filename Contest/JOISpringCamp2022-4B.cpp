#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct DSU {
	int parent[maxN], sz[maxN];
	
	void reset(){
		for(int x=0;x<maxN;x++){
			parent[x] = x;
			sz[x] = 1;
		}
	}
	
	int getParent(int x){
		if(parent[x] == x) return x;
		return parent[x] = getParent(parent[x]);
	}
	
	void merge(int x, int y){
		int a = getParent(x);
		int b = getParent(y);
		
		if(a != b){
			if(sz[a] < sz[b]){
				swap(a, b);
			}
			
			parent[b] = a;
			sz[a] += sz[b];
		}
	}
};

struct SegmentTree {
	pair<int, ll> tree[2*maxN];
	int n;
	
	void build(int n, int a[]){
		this->n = n;
		for(int x=0;x<n;x++){
			tree[n+x] = {a[x], a[x]};
		}
		
		for(int x=n-1;x>0;x--){
			tree[x] = {max(tree[x<<1].first, tree[x<<1 | 1].first), tree[x<<1].second+tree[x<<1 | 1].second};
		}
	}	
	
	void update(int pos, int val){
		pos += n;
		
		tree[pos] = {val, val};
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = {max(tree[x].first, tree[x^1].first), tree[x].second+tree[x^1].second};
		}
	}
	
	pair<int, ll> query(int left, int right){ // [L, R)
		pair<int, ll> ans = {0, 0};
		
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans.first = max(ans.first, tree[left].first);
				ans.second += tree[left].second;
				left++;
			}
			if(right&1){
				right--;
				ans.first = max(ans.first, tree[right].first);
				ans.second += tree[right].second;
			}
		}
		return ans;
	}
};

SegmentTree tree;
DSU dsu;
vector<int> adj[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	tree.build(n, a);
	
	int q;
	cin >> q;
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos, val;
			cin >> pos >> val;
			
			pos--;
			a[pos] = val;
			tree.update(pos, val);
		} else if(t == 2){
			int l, r;
			cin >> l >> r;
			
			dsu.reset();
			l--; r--;
			
			for(int x=l;x<=r;x++){
				int pos = r+1;
				int left = x+1, right = r;
				while(left <= right){
					int mid = (left+right) >> 1;
					
					pair<int, ll> p = tree.query(x+1, mid+1);
					
					if(p.first > a[x]){
						pos = mid;
						right = mid-1;
					} else {
						left = mid+1;
					}
				}
				
				cout << "R " << x << " -> " << pos << "\n";
				if(pos <= r && tree.query(x, pos).second >= a[pos]){
					cout << "ok\n";
					dsu.merge(pos, x);
				}
				if(pos > x+1 && a[x] >= a[pos-1]){
					dsu.merge(x, pos-1);
				}
				
				pos = l-1;
				left = l, right = x-1;
				while(left <= right){
					int mid = (left+right) >> 1;
					
					pair<int, ll> p = tree.query(mid, x);
					
					if(p.first > a[x]){
						pos = mid;
						left = mid+1;
					} else {
						right = mid-1;
					}
				}
				
				cout << "L " << x << " -> " << pos << "\n";
				if(pos >= l && tree.query(pos+1, x+1).second >= a[pos]){
					cout << "ok\n";
					dsu.merge(pos, x);
				}
				if(pos < x-1 && a[x] >= a[pos+1]){
					dsu.merge(x, pos+1);
				}
			}
			
			int ans = 0;
			for(int x=l;x<=r;x++){
				if(a[l] != a[r]){
					if(dsu.getParent(x) == dsu.getParent(l) && dsu.getParent(x) == dsu.getParent(r)){
						ans++; cout << x << "\n";
					}
				} else {
					if(dsu.getParent(x) == dsu.getParent(l) || dsu.getParent(x) == dsu.getParent(r)){
						ans++; cout << x << "\n";
					}
				}
			}
			
			cout << ans << "\n";
		} else {
			assert(false);
		}
	}
	
    return 0;
}

