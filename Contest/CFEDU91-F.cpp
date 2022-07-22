#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e5 + 5;
const int logN = log2(maxN)+1;
const ll mod = 998244353;

struct SegmentTree {
	ll tree[4*maxN][4];
	int b[maxN];
	
	void reset(){
		fill(tree[0], tree[4*maxN], 0);
	}
	
	void merge(int v, int l, int r){
		int m = (l+r) >> 1;
		
		int num = b[m]*10 + b[m+1];
		int mn = 0;
		for(int x=0;x<10;x++){
			for(int y=0;y<10;y++){
				if(x+y == num) mn++;
			}
		}
		
		// case for 0
		tree[v][0] = tree[2*v+1][0]*tree[2*v+2][0] % mod + tree[2*v+1][2]*tree[2*v+2][1] % mod * mn % mod;
		
		// case for 1
		tree[v][1] = tree[2*v+1][1]*tree[2*v+2][0] % mod + tree[2*v+1][3]*tree[2*v+2][1] % mod * mn % mod;
		
		// case for 2
		tree[v][2] = tree[2*v+1][0]*tree[2*v+2][2] % mod + tree[2*v+1][2]*tree[2*v+2][3] % mod * mn % mod;
		
		// case for 3
		tree[v][3] = tree[2*v+1][1]*tree[2*v+2][2] % mod + tree[2*v+1][3]*tree[2*v+2][3] % mod * mn % mod;
		
		for(int x=0;x<4;x++){
			if(tree[v][x] >= mod) tree[v][x] -= mod;
		}
	}
	
	void build(int v, int l, int r, int a[]){
		if(l > r) return;
		if(l == r){
			for(int x=0;x<4;x++) tree[v][x] = 0;
			
			if(a[l] == 1){
				tree[v][2] = 1;
			}
			if(a[l] <= 9){
				tree[v][1] = 1;
			}
			tree[v][0] = a[l]+1;
			b[l] = a[l];
			return;
		}
		
		int m = (l+r)>>1;
		build(2*v+1, l, m, a);
		build(2*v+2, m+1, r, a);
		
		merge(v, l, r);
	}
	
	void update(int v, int curL, int curR, int pos, int val){
		if(curL > curR) return;
		if(curL == curR){
			for(int x=0;x<4;x++) tree[v][x] = 0;
			
			if(val == 1){
				tree[v][2] = 1;
			}
			if(val <= 9){
				tree[v][1] = 1;
			}
			tree[v][0] = val+1;
			b[curL] = val;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		if(pos <= curM){
			update(2*v+1, curL, curM, pos, val);
		} else {
			update(2*v+2, curM+1, curR, pos, val);
		}
		
		merge(v, curL, curR);
	}
	
	void solve(ll val[], int v, int l, int last){
		int num = last*10 + b[l];
		int mn = 0;
		for(int x=0;x<10;x++){
			for(int y=0;y<10;y++){
				if(x+y == num) mn++;
			}
		}
		
		// case for 0
		val[0] = val[0]*tree[v][0] % mod + val[2]*tree[v][1]*mn % mod;
		
		// case for 1
		val[1] = val[1]*tree[v][0] % mod + val[3]*tree[v][1]*mn % mod;
		
		// case for 2
		val[2] = val[0]*tree[v][2] % mod + val[2]*tree[v][3]*mn % mod;
		
		// case for 3
		val[3] = val[1]*tree[v][2] % mod + val[3]*tree[v][3]*mn % mod;
	}
	
	void query(int v, int curL, int curR, int l, int r, ll val[], int &last){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			solve(val, v, curL, last);
			return;
		}
		
		int curM = (curL+curR) >> 1;
		
		query(2*v+1, curL, curM, l, min(curM, r), val, last);
		
		last = b[curM];
		
		query(2*v+1, curM+1, curR, max(curM+1, l), r, val, last);
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int a[n];
	for(int x=0;x<n;x++){
		char c;
		cin >> c;
		
		a[x] = (c - '0');
	}
	
	tree.reset();
	tree.build(0, 0, n-1, a);
	
	auto ans = [&]() -> ll {
		int last = 0;
		ll val[4];
		fill(val, val+4, 0);
		
		val[0] = 1;
		tree.query(0, 0, n-1, 0, n-1, val, last);
		
		return val[0]; 
	};
	
	while(q--){
		int pos, val;
		cin >> pos >> val;
		
		pos--;
		tree.update(0, 0, n-1, pos, val);
		
		cout << ans() << "\n";
	}
    return 0;
}

