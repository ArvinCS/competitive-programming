#include <bits/stdc++.h>

using namespace std;

struct SegTree {
	vector<int> tree, lazy;
	
	int n;
	void resize(int m){
		n = m;
		tree = lazy = vector<int>(4*n+5, 0);
	}
	
	void push(int v){
		tree[v*2+1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(curL > r || l > r || curL > curR) return;
		if(curL == l && r == curR){
			tree[v] += val;
			lazy[v] += val;
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
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, d;
	cin >> n >> d;
	
	string s;
	cin >> s;
	
	int q;
	cin >> q;
	
	tree.resize(n);
	
	for(int x=0;x<n;x++){
		if(s[x] == '1'){
			tree.update(0, 0, n-1, x, x+d-1, 1);
		}
	}
	
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos;
			cin >> pos;
			
			pos--;
			
			if(s[pos] == '1'){
				tree.update(0, 0, n-1, pos, pos+d-1, -1);
				s[pos] = '0';
			} else {
				tree.update(0, 0, n-1, pos, pos+d-1, 1);
				s[pos] = '1';
			}
		} else {
			int val;
			cin >> val;
			
			int left = 0, right = n-1;
			int ans = right+1;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(tree.query(0, 0, n-1, 0, mid) > val){
					ans = min(ans, mid);
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			
			if(ans < n){
				cout << ans+1 << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}

    return 0;
}

