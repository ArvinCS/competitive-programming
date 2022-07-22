#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2 * (2e5 + 5);
const int logN = log2(maxN)+1;

struct SegTree {
	int tree[4*maxN], lazy[4*maxN];
	
	void reset(){
		fill(tree, tree+4*maxN, 1e9);
		fill(lazy, lazy+4*maxN, 1e9);
	}
	
	void push(int v){
		if(lazy[v] == 1e9) return;
		
		tree[v*2+1] = min(tree[2*v+1], lazy[v]);
		lazy[v*2+1] = min(lazy[2*v+1], lazy[v]);
		
		tree[v*2+2] = min(tree[2*v+2], lazy[v]);
		lazy[v*2+2] = min(lazy[2*v+2], lazy[v]);
		
		lazy[v] = 1e9;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(curL > curR || l > r) return;
		if(curL == l && r == curR){
			if(tree[v] > val){
				tree[v] = val;
				lazy[v] = min(lazy[v], val);
			}
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 1e9;
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
	}
} tree, border;

int jump[logN][maxN];

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
	
	border.reset();
	
	vector<array<int, 3>> w;

	for(int x=0;x<n;x++){
		w.push_back({p[x].first, 1, x});
		w.push_back({p[x].second+1, 0, x});
	}
	
	sort(w.begin(), w.end());

	bool active[n];
	fill(active, active+n, false);

	int mn[n];
	fill(mn, mn+n, n);

	for(int x=0;x<w.size();x++){
		if(w[x][1] == 1){
			for(int y=0;y<w[x][2];y++){
				if(active[y]) mn[y] = min(mn[y], w[x][2]);
			}
			for(int y=w[x][2]+1;y<n;y++){
				if(active[y]){
					mn[w[x][2]] = min(mn[w[x][2]], y);
					break;
				}
			}
		}
		active[w[x][2]] ^= 1;
	}
	
	int cur = n;
	for(int y=0;y<logN;y++){
		jump[y][n] = n;
	}
	for(int x=n-1;x>=0;x--){
		cur = min(cur, mn[x]);
			
		jump[0][x] = cur;
		for(int y=1;y<logN;y++){
			jump[y][x] = jump[y-1][jump[y-1][x]];
		}
	}
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		int l, r;
		cin >> l >> r;
		
		l--; r--;
		
		int pos = l;
		int ans = 1;
		for(int x=logN-1;x>=0;x--){
			if(jump[x][pos] <= r){
				pos = jump[x][pos];
				ans += (1 << x);
			}
		}
		
		cout << ans << "\n";
	}
    return 0;
}

