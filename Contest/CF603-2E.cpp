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

const int maxN = 1e6 + 5;

struct SegTree { // index start from 0 (v)
	int tree[4*maxN][2], lazy[4*maxN];
	
	void reset(){
		fill(tree[0], tree[4*maxN], 0);
		fill(lazy, lazy+4*maxN, 0);
	}
	
	void push(int v){
		tree[v*2+1][0] += lazy[v];
		tree[v*2+1][1] += lazy[v];
		lazy[v*2+1] += lazy[v];
		
		tree[v*2+2][0] += lazy[v];
		tree[v*2+2][1] += lazy[v];
		lazy[v*2+2] += lazy[v];
		
		lazy[v] = 0;
	}
	
	void update(int v, int curL, int curR, int l, int r, int val){
		if(l > r) return;
		if(curL == l && r == curR){
			tree[v][0] += val;
			tree[v][1] += val;
			lazy[v] += val;
		} else {
			push(v);
			
			int curM = (curL+curR) >> 1;
			
			update(v*2+1, curL, curM, l, min(r, curM), val);
			update(v*2+2, curM+1, curR, max(l, curM+1), r, val);
			
			tree[v][0] = max(tree[v*2+1][0], tree[v*2+2][0]);
			tree[v][1] = min(tree[v*2+1][1], tree[v*2+2][1]);
		}
	}
	
	pair<int, int> query(int v, int curL, int curR, int l, int r){
		if(l > r || curL > curR) return {-inf_int, inf_int};
		if(l <= curL && curR <= r){
			return {tree[v][0], tree[v][1]};
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		pair<int, int> p = query(v*2+1, curL, curM, l, min(r, curM)), q = query(v*2+2, curM+1, curR, max(l, curM+1), r);
		return {max(p.first, q.first), min(p.second, q.second)};
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
	
	char c[n];
	for(int x=0;x<n;x++){
		cin >> c[x];
	}
	
	tree.reset();
	
	int pos = 0, sum = 0;
	for(int x=0;x<n;x++){
		if(c[x] == 'L'){
			pos = max(0, pos-1);
		} else if(c[x] == 'R'){
			pos++;
		} else {
			int prv = tree.query(0, 0, n-1, pos, pos).first - (pos > 0 ? tree.query(0, 0, n-1, pos-1, pos-1).first : 0);
			sum -= prv;
			
//			cout << x << " " << pos << " -> " << prv << " " << tree.query(0, 0, n-1, pos, pos).first << " " << (pos > 0 ? tree.query(0, 0, n-1, pos-1, pos-1).first : 0) << "\n";
			if(c[x] == '('){
				tree.update(0, 0, n-1, pos, n-1, 1-prv);
				sum++;
			} else if(c[x] == ')'){
				tree.update(0, 0, n-1, pos, n-1, -1-prv);
				sum--;
			} else {
				tree.update(0, 0, n-1, pos, n-1, -prv);
			}
		}
		
		pair<int, int> p = tree.query(0, 0, n-1, 0, n-1);
		if(x > 0) cout << " ";
		if(p.second < 0 || sum != 0){
			cout << "-1";
		} else {
			cout << p.first;
		}
	}
    return 0;
}

