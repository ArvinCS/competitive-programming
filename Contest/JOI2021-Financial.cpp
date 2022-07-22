#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 3e5 + 5;

struct SegTree { // index start from 0 (v)
	int tree[4*maxN], lazy[4*maxN];
	
	int n;
	void resize(int m){
		n = m;
	}
	
	void push(int v){
		if(lazy[v] == -1) return ;
		
		tree[v*2+1] = lazy[v];
		lazy[v*2+1] = lazy[v];
		
		tree[v*2+2] = lazy[v];
		lazy[v*2+2] = lazy[v];
		
		lazy[v] = -1;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] = val;
			lazy[v] = val;
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

	int n, d;
	cin >> n >> d;
	
	vector<int> v;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();	
	}
	
	tree.update(0, 0, v.size()-1, a[0], a[0], 1);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({a[0], 0});
	
	for(int x=1;x<n;x++){
		while(!pq.empty() && x-pq.top().second > d){
			pq.pop();
		}
		
		tree.update(0, 0, v.size()-1, 0, pq.top().first-1, 0);
		int val = tree.query(0, 0, v.size()-1, pq.top().first, a[x]-1)+1;
		int val2 = tree.query(0, 0, v.size()-1, a[x], a[x]);
		
//		cout << x+1 << "(" << a[x] << ") -> " << val << " " << val2 << " " << pq.top().first << "\n";
//		cout << x << "(" << a[x] << "): " << p.first << " " << p.second << " " << pq.top().first << "\n";
		
		tree.update(0, 0, v.size()-1, a[x], a[x], max(val, val2));
		pq.push({a[x], x});
	}
	while(!pq.empty() && n-1-pq.top().second > d){
		pq.pop();
	}
		
	cout << tree.query(0, 0, v.size()-1, pq.top().first, v.size()-1) << "\n";
    return 0;
}

