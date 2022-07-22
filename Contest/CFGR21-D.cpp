#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e5 + 5;

struct SegTree { // index start from 0 (v)
	int tree[4*maxN];
	
	void reset(int n = maxN){
		fill(tree, tree+4*n, 1e9);
	}
	
	void update(int v, int curL, int curR, int pos, int val){
		if(curL > curR) return;
		if(curL == curR && curL == pos){
			tree[v] = val;
		} else {			
			int curM = (curL+curR) >> 1;
			
			if(pos <= curM) update(v*2+1, curL, curM, pos, val);
			else update(v*2+2, curM+1, curR, pos, val);
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 1e9;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
} tree, mn, mn2, lst;

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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
		}
		
		tree.reset(n+1);
		mn.reset(n+1);
		mn2.reset(n+1);
		lst.reset(n+1);
		
		int ans = 0;
		stack<array<int, 3>> st, st2;
		mn.update(0, 0, n-1, n-1, 0); mn2.update(0, 0, n-1, n-1, 0);
		st.push({a[n-1], n-1, 0}); st2.push({a[n-1], n-1, 0});
		
		for(int x=n-2;x>=0;x--){
			while(!st.empty() && st.top()[0] <= a[x]){
				mn.update(0, 0, n-1, st.top()[1], 1e9);
				st.pop();
			}
			while(!st2.empty() && st2.top()[0] >= a[x]){
				mn2.update(0, 0, n-1, st2.top()[1], 1e9);
				st2.pop();
			}
			
			int val = 1e9;
			if(a[x] < a[x+1]){
				int bound = min(n-1, lst.query(0, 0, n-1, 0, a[x]-1)-1);
				val = min(val, mn.query(0, 0, n-1, x+1, bound));
			} else {
				int bound = min(n-1, lst.query(0, 0, n-1, a[x]+1, n-1)-1);
				val = min(val, mn2.query(0, 0, n-1, x+1, bound));
			}
			
			if(x == 0){
				ans = val+1;
			}
			
			mn.update(0, 0, n-1, x, val+1);
			mn2.update(0, 0, n-1, x, val+1);
			st.push({a[x], x, val+1});
			st2.push({a[x], x, val+1});
			lst.update(0, 0, n-1, a[x], x);
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

