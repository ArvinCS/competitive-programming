#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 1e6;

struct SegmentTree {
	array<ll, 3> tree[4*maxA];
	
	void build(int v, int curL, int curR, ll cnt[], ll extra = 0){
		if(curL > curR){
			tree[v][0] = -1e18;
			tree[v][1] = -1e18;
			tree[v][2] = 0;
			return;
		}
		
		if(curL == curR){
			tree[v][2] = cnt[curL];
			tree[v][0] = tree[v][2];
			tree[v][1] = curL;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		build(2*v+2, curM+1, curR, cnt, extra);
		build(2*v+1, curL, curM, cnt, extra+tree[2*v+2][2]);
		
		tree[v][2] = (tree[2*v+1][2] + tree[2*v+2][2]);
		
		if(tree[2*v+1][0]+tree[2*v+2][2] > tree[2*v+2][0]){
			tree[v][0] = tree[2*v+1][0]+tree[2*v+2][2];
			tree[v][1] = tree[2*v+1][1];
		} else {
			tree[v][0] = tree[2*v+2][0];
			tree[v][1] = tree[2*v+2][1];
		}
	}
	
	void update(int v, int curL, int curR, int pos, ll val){
		if(curL > curR) return;
		if(curL == curR){
			tree[v][2] += val;
			tree[v][0] = tree[v][2];
			tree[v][1] = curL;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		if(pos <= curM){
			update(2*v+1, curL, curM, pos, val);
		} else {
			update(2*v+2, curM+1, curR, pos, val);
		}
		
		tree[v][2] = (tree[2*v+1][2] + tree[2*v+2][2]);
		
		if(tree[2*v+1][0]+tree[2*v+2][2] > tree[2*v+2][0]){
			tree[v][0] = tree[2*v+1][0]+tree[2*v+2][2];
			tree[v][1] = tree[2*v+1][1];
		} else {
			tree[v][0] = tree[2*v+2][0];
			tree[v][1] = tree[2*v+2][1];
		}
	}
	
	ll query(int v, int curL, int curR, ll extra = 0){
		if(curL > curR) return -1;
		if(curL == curR){
			return curL;
		}
		
		int curM = (curL+curR) >> 1;
		
		if(tree[2*v+2][0]+extra > 0){
			return query(2*v+2, curM+1, curR, extra);
		} else if(tree[2*v+1][0]+tree[2*v+2][2]+extra > 0){
			return query(2*v+1, curL, curM, extra+tree[2*v+2][2]);
		} else {
			return -1;
		}
	}
} tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> w;
	int a[n], b[m];
	for(int x=0;x<n;x++){
		cin >> a[x];
		w.push_back(a[x]);
	}
	for(int x=0;x<m;x++){
		cin >> b[x];
		w.push_back(b[x]);
	}
	
	int q;
	cin >> q;
	
	vector<array<int, 3>> v;
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos, val;
			cin >> pos >> val;
			
			pos--;
			v.push_back({t, pos, val});
			w.push_back(val);
		} else if(t == 2){
			int pos, val;
			cin >> pos >> val;
			
			pos--;
			v.push_back({t, pos, val});
			w.push_back(val);
		} else {
			assert(false);
		}
	}
	
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	
	for(int x=0;x<n;x++){
		a[x] = lower_bound(w.begin(), w.end(), a[x]) - w.begin();
	}
	for(int x=0;x<m;x++){
		b[x] = lower_bound(w.begin(), w.end(), b[x]) - w.begin();
	}
	for(int x=0;x<v.size();x++){
		v[x][2] = lower_bound(w.begin(), w.end(), v[x][2]) - w.begin();
	}
	
	ll cnt[w.size()];
	fill(cnt, cnt+w.size(), 0);
	
	for(int x=0;x<n;x++){
		cnt[a[x]]++;
	}
	for(int x=0;x<m;x++){
		cnt[b[x]]--;
	}
	
	tree.build(0, 0, w.size()-1, cnt);
	
	for(int x=0;x<v.size();x++){
		int t = v[x][0];
		int pos = v[x][1];
		int val = v[x][2];
		
		if(t == 1){
			int prv = a[pos];
			
			cnt[prv]--;
			a[pos] = val;
			cnt[val]++;
			
			tree.update(0, 0, w.size()-1, prv, -1);
			tree.update(0, 0, w.size()-1, val, 1);
		} else {
			int prv = b[pos];
			
			cnt[prv]++;
			b[pos] = val;
			cnt[val]--;
			
			tree.update(0, 0, w.size()-1, prv, 1);
			tree.update(0, 0, w.size()-1, val, -1);
		}
		
		int ans = tree.query(0, 0, w.size()-1);
		cout << (ans >= 0 ? w[ans] : -1) << "\n";
	}
    return 0;
}

