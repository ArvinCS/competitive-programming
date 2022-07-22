#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int mod = 1e9 + 7;

struct Matrix {
	ll m[2][2];
	
	Matrix(ll a = 0, ll b = 0, ll c = 0, ll d = 0){
		m[0][0] = a;
		m[0][1] = b;
		m[1][0] = c;
		m[1][1] = d;
	}
	
	Matrix operator *(const Matrix &b) const {
		Matrix nw(0,0,0,0);
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				for(int z=0;z<2;z++){
					nw.m[x][z] += m[x][y] * 1ll * b.m[y][z] % mod;
					nw.m[x][z] %= mod;
				}
			}
		}
		return nw;
	}
};

struct SegmentTree {
	Matrix tree[8*maxN];
	bool lazy[8*maxN];
	
	void reset(){
		fill(tree, tree+8*maxN, Matrix(1, 0, 0, 1));
		fill(lazy, lazy+8*maxN, false);
	}
	
	void build(int v, int l, int r, string &s){
		if(l > r){
			return;
		}
		if(l == r){
			if(s[l] == 'A'){
				tree[v] = Matrix(1, 1, 0, 1);
			} else if(s[l] == 'B'){
				tree[v] = Matrix(1, 0, 1, 1);
			} else {
				assert(false);
			}
			return;
		}
		
		int m = (l+r) >> 1;
		build(2*v+1, l, m, s);
		build(2*v+2, m+1, r, s);
		
		tree[v] = tree[2*v+2] * tree[2*v+1];
	}
	
	void push(int v){
		if(!lazy[v]) return;
		
		for(int y=0;y<2;y++){
			swap(tree[2*v+1].m[0][y], tree[2*v+1].m[1][y^1]);
			swap(tree[2*v+2].m[0][y], tree[2*v+2].m[1][y^1]);
		}
		
		lazy[2*v+1] ^= lazy[v];
		lazy[2*v+2] ^= lazy[v];
		
		lazy[v] = false;
	}
	
	void update(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return;
		if(curL == l && curR == r){
			for(int y=0;y<2;y++){
				swap(tree[v].m[0][y], tree[v].m[1][y^1]);
			}
			lazy[v] ^= 1;
			return;
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		update(2*v+1, curL, curM, l, min(curM, r));
		update(2*v+2, curM+1, curR, max(l, curM+1), r);
		
		tree[v] = tree[2*v+2] * tree[2*v+1];
	}
	
	Matrix query(int v, int curL, int curR, int l, int r){
		if(curL > curR || l > r) return Matrix(1, 0, 0, 1);
		if(curL == l & curR == r){
			return tree[v];
		}
		
		push(v);
		
		int curM = (curL+curR) >> 1;
		
		return query(2*v+2, curM+1, curR, max(l, curM+1), r) * query(2*v+1, curL, curM, l, min(curM, r));
	}
} tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	tree.build(0, 0, n-1, s);
	
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			tree.update(0, 0, n-1, l, r);
		} else if(t == 2){
			int l, r;
			ll a, b;
			cin >> l >> r >> a >> b;
			
			l--; r--;
			
			Matrix m = tree.query(0, 0, n-1, l, r);
			m = m * Matrix(a, 0, 0, b);
			
			assert((m.m[0][0]+m.m[0][1])%mod >= 0 && (m.m[0][0]+m.m[0][1])%mod < mod);
			assert((m.m[1][0]+m.m[1][1])%mod >= 0 && (m.m[1][0]+m.m[1][1])%mod < mod);
			
			cout << (m.m[0][0]+m.m[0][1])%mod << " " << (m.m[1][0]+m.m[1][1])%mod << "\n";
		} else {
			assert(false);
		}
	}
    return 0;
}

