#include <bits/stdc++.h>

using namespace std;

const int maxA = 2e5 + 5;

int cnt[maxA], front[maxA], back[maxA];

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
		if(l > r) return;
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
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	fill(cnt, cnt+maxA, 0);
	fill(front, front+maxA, n+1);
	fill(back, back+maxA, -1);
	
	tree.resize(n);
	
	for(int x=0;x<n;x++){
		cnt[a[x]]++;
	}
	
	int ans = 0;
	for(int x=n-1;x>=0;x--){
		cnt[a[x]]--;
		
		if(back[a[x]] != -1){
			if(front[a[x]] < back[a[x]]) tree.update(0, 0, n-1, front[a[x]], back[a[x]], -1);
		}
			
		if(cnt[a[x]] > 0){
			if(back[a[x]] == -1) back[a[x]] = x;
			front[a[x]] = x;
			
			if(front[a[x]] < back[a[x]]) tree.update(0, 0, n-1, front[a[x]], back[a[x]], 1);
		}
		
		ans = max(ans, tree.query(0, 0, n-1, x, n-1));
	}
	
	cout << ans << "\n";
    return 0;
}

