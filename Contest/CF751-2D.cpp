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

vector<int> adj[maxN];

struct SegTree { // index start from 0 (v)
	pair<ll, int> tree[8*maxN], lazy[8*maxN];
	
	void reset(){		
		fill(tree, tree+8*maxN, make_pair(inf_ll, inf_int));
		fill(lazy, lazy+8*maxN, make_pair(inf_ll, inf_int));
	}
	
	void push(int v){
		tree[v*2+1] = min(tree[v*2+1], lazy[v]);
		lazy[v*2+1] = min(lazy[v*2+1], lazy[v]);
		
		tree[v*2+2] = min(tree[v*2+2], lazy[v]);
		lazy[v*2+2] = min(lazy[v*2+2], lazy[v]);
		
		lazy[v] = make_pair(inf_ll, inf_int);
	}
	
	void update(int v, int curL, int curR, int l, int r, pair<ll, int> val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v] = min(tree[v], val);
			lazy[v] = min(lazy[v], val);
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v] = min(tree[v*2+1], tree[v*2+2]);
		}
	}
	
	pair<ll, int> query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return make_pair(inf_ll, inf_int);
		if(l <= curL && curR <= r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return min(query(v*2+1, curL, curM, l, min(r, curM)), query(v*2+2, curM+1, curR, max(l, curM+1), r));
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
	
	int a[n+1], b[n+1];
	a[0] = 0; b[0] = 0;
	for(int x=1;x<=n;x++){
		cin >> a[x];
	}
	for(int x=1;x<=n;x++){
		cin >> b[x];
		adj[x+b[x]].push_back(x);
	}
	
	tree.reset();
	
	for(int x=1;x<=n;x++){
		int pos = -1;
		ll mn = inf_ll;
		for(int y=0;y<adj[x].size();y++){
			ll tmp = tree.query(0, 0, n, adj[x][y], adj[x][y]).first;
			if(mn > tmp){
				mn = tmp;
				pos = y;
			}
		}
		
		if(pos == -1){
			continue;
		}
		
		table[x] = mn;
		tree.update(0, 0, n, max(0, x-a[x]), x-1, make_pair(mn+1, adj[x][pos]));
	}
	
	pair<ll, int> p = tree.query(0, 0, n, 0, 0);
	if(p.second == inf_int || p.first == inf_ll){
		cout << "-1\n";
		return 0;
	}
	
	vector<ll> v;
	int cur = p.second;
	
	v.push_back(0);
	while(cur < n){
		v.push_back(cur);
		cur = tree.query(0, 0, n, cur, cur).second;	
	}
//	v.push_back(0);
	
	reverse(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for(int x=0;x<v.size();x++){
		if(x > 0) cout << " ";
		cout << v[x];
	}
	cout << "\n";
    return 0;
}


