#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

struct SegTree {
	int tree[2*maxN];
	
	void reset(){
		fill(tree, tree+2*maxN, 0);
	}
	
	int query(int l, int r){
		int ans = 0;
		for(l += maxN, r += maxN; l < r; l >>= 1, r >>= 1){
			if(l&1) ans = max(ans, tree[l++]);
			if(r&1) ans = max(ans, tree[--r]);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos += maxN;
		
		tree[pos] = max(tree[pos], val);
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = max(tree[x], tree[x^1]);
		}
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v[n+1];
	int p[n], q[n], pos[n+1];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	for(int x=0;x<n;x++){
		cin >> q[x];
		pos[q[x]] = x;
	}
	
	for(int x=1;x<=n;x++){
		for(int y=x;y<=n;y+=x){
			v[x].push_back(pos[y]);		
		}
		
		sort(v[x].rbegin(), v[x].rend());
	}
	
	tree.reset();
	
	int ans = 0;
	for(int x=0;x<n;x++){
		for(auto r : v[p[x]]){
			int mx = tree.query(0, r);
			tree.update(r, mx+1);
			
			ans = max(ans, mx+1);		
		}
	}
	
	cout << ans << "\n";
    return 0;
}

