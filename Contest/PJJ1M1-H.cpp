#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

vector<int> adj[maxN];
int inTime[maxN], id[maxN], sz[maxN], a[maxN], t = 0;

struct SegTree { // index start from 0 (v)
	int tree[4*maxN][2], lazy[4*maxN];
	
	void resize(int m){
		fill(tree[0], tree[4*maxN], 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void build(int v, int l, int r){
		if(l > r) return;
		if(l == r){
			tree[v][a[id[l]]]++;
			return;
		}
		
		int m = (l+r)/2;
		build(v*2+1, l, m);
		build(v*2+2, m+1, r);
		
		tree[v][0] = tree[v*2+1][0] + tree[v*2+2][0];
		tree[v][1] = tree[v*2+1][1] + tree[v*2+2][1];
	}
	
	void push(int v){
		if(lazy[v]&1) swap(tree[v*2+1][0], tree[v*2+1][1]);
		lazy[v*2+1] += lazy[v];
		
		if(lazy[v]&1) swap(tree[v*2+2][0], tree[v*2+2][1]);
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			swap(tree[v][0], tree[v][1]);
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v][0] = tree[v*2+1][0] + tree[v*2+2][0];
			tree[v][1] = tree[v*2+1][1] + tree[v*2+2][1];
		}
	}
	
	int query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return 0;
		if(l <= curL && curR <= r){
			return tree[v][1];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		return query(v*2+1, curL, curM, l, min(r, curM)) + query(v*2+2, curM+1, curR, max(l, curM+1), r);
	}
};

void dfs(int curNode, int prvNode){
	sz[curNode] = 1;
	inTime[curNode] = t++;
	id[inTime[curNode]] = curNode;
	
	for(auto nxt : adj[curNode]){
		if(nxt != prvNode){
			dfs(nxt, curNode);
			sz[curNode] += sz[nxt];
		}
	}
}

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=1;x<n;x++){
		int p;
		cin >> p;
		
		p--;
		adj[p].push_back(x);
	}
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	dfs(0, 0);
	tree.build(0, 0, n-1);
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		string s;
		int v;
		cin >> s >> v;
		
		v--;
		if(s == "pow"){
			tree.update(0, 0, n-1, inTime[v], inTime[v]+sz[v]-1, 1);
		} else {
			cout << tree.query(0, 0, n-1, inTime[v], inTime[v]+sz[v]-1) << "\n";
		}
	}
    return 0;
}

