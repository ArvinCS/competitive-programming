#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct SegmentTree {
	ll prefix[4*maxN];
	ll suffix[4*maxN];
	ll tree[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 0);
		fill(suffix, suffix+4*maxN, -1e17);
		fill(prefix, prefix+4*maxN, -1e17);
	}
	
	void build(int v, int l, int r, ll a[]){
		if(l > r){
			prefix[v] = suffix[v] = -1e17;
			tree[v] = 0;
			return;
		}
		if(l == r){
			tree[v] = prefix[v] = suffix[v] = a[l];
			return;
		}
		
		int m = (l+r) >> 1;
		
		build(2*v+1, l, m, a);
		build(2*v+2, m+1, r, a);
		
		if(l <= m && m < r){
			if(prefix[2*v+1] <= tree[2*v+1]+prefix[2*v+2]){
				prefix[v] = tree[2*v+1]+prefix[2*v+2];
			} else {
				prefix[v] = prefix[2*v+1];
			}
			
			if(suffix[2*v+1]+tree[2*v+2] >= suffix[2*v+2]){
				suffix[v] = suffix[2*v+1]+tree[2*v+2];
			} else {
				suffix[v] = suffix[2*v+2];
			}
		} else if(l <= m){
			prefix[v] = prefix[2*v+1];
			suffix[v] = suffix[2*v+1];
		} else if(m < r){
			prefix[v] = prefix[2*v+2];
			suffix[v] = suffix[2*v+2];
		}
		
		tree[v] = tree[2*v+1] + tree[2*v+2];
	}
	
	pair<ll, ll> queryPrefix(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return {-1e17, 0};
		if(curL == l && curR == r){
			return {prefix[v], tree[v]};
		}
		
		int curM = (curL+curR) >> 1;
		
		pair<ll, ll> a = queryPrefix(2*v+1, curL, curM, l, min(r, curM));
		pair<ll, ll> b = queryPrefix(2*v+2, curM+1, curR, max(l, curM+1), r);
		
		if(a.second+b.first >= a.first){
			return {a.second+b.first, a.second+b.second};
		} else {
			return {a.first, a.second+b.second};
		}
	}
	
	pair<ll, ll> querySuffix(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return {-1e17, 0};
		if(curL == l && curR == r){
			return {suffix[v], tree[v]};
		}
		
		int curM = (curL+curR) >> 1;
		
		pair<ll, ll> a = querySuffix(2*v+1, curL, curM, l, min(r, curM));
		pair<ll, ll> b = querySuffix(2*v+2, curM+1, curR, max(l, curM+1), r);
		
		if(b.second+a.first >= b.first){
			return {b.second+a.first, a.second+b.second};
		} else {
			return {b.first, a.second+b.second};
		}
	}
} tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	tree.reset();
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		tree.build(0, 0, n-1, a);
		
		vector<ll> v;
		for(int x=0;x<n;x++){
			v.push_back(a[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		vector<int> comp[v.size()];
		for(int x=0;x<n;x++){
			comp[lower_bound(v.begin(), v.end(), a[x]) - v.begin()].push_back(x);
		}
		
		bool possible = true;
		set<int> st;
		for(int x=v.size()-1;x>=0;x--){
			for(int y=0;y<comp[x].size();y++){
				auto it = st.lower_bound(comp[x][y]);
				
				int l = 0, r = n-1;
				if(it != st.end()){
					r = *it - 1;
				}
				if(it != st.begin()){
					it--;
					l = *it + 1;
				}
				
				ll sum = tree.querySuffix(0, 0, n-1, l, comp[x][y]).first+tree.queryPrefix(0, 0, n-1, comp[x][y], r).first-v[x];
				if(sum <= -1e17 || sum > v[x]){
					possible = false;
				}
			}
			for(auto idx : comp[x]){
				st.insert(idx);
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

