#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const ll mod = 998244353;

struct Matrix {
	vector<vector<ll>> a;
	
	Matrix(){
		
	}
	
	Matrix(vector<vector<ll>> a) : a(a){
		
	}
	
	Matrix operator * (const Matrix &other) const {
		vector<vector<ll>> b;
		for(int x=0;x<a.size();x++){
			vector<ll> w(other.a[0].size(), 0);
			b.push_back(w);
		}
		
		for(int x=0;x<a.size();x++){
			for(int y=0;y<a[x].size();y++){
				for(int z=0;z<other.a.size();z++){
					b[x][z] += a[x][y] * other.a[y][z] % mod;	
					b[x][z] %= mod;
				}
			}
		}
		return Matrix(b);
	}
};

const Matrix MatrixZero({{1, 1, 1}, {0, 1, 0}, {0, 0, 1}});
const Matrix MatrixOne({{1, 0, 0}, {1, 1, 1}, {0, 0, 1}});
const Matrix MatrixBoth({{1, 1, 1}, {1, 1, 1}, {0, 0, 1}});
const Matrix MatrixInitial({{0}, {0}, {1}});

struct SegmentTree {
	Matrix tree[4*maxN];
	
	void build(int v, int l, int r, string &s){
		if(l > r) return;
		if(l == r){
			if(s[l] == '?'){
				tree[v] = MatrixBoth;
			} else if(s[l] == '0'){
				tree[v] = MatrixZero;
			} else {
				tree[v] = MatrixOne;
			}
			return;
		}
		
		int m = (l+r) >> 1;
		
		build(2*v+1, l, m, s);
		build(2*v+2, m+1, r, s);
		
		if(m+1 > r){
			tree[v] = tree[2*v+1];
			return;
		}
		
		tree[v] = (tree[2*v+1] * tree[2*v+2]);
	}
	
	void update(int v, int l, int r, int pos, int val){
		if(l > r) return;
		if(l == r){
			if(val == 2){
				tree[v] = MatrixBoth;
			} else if(val == 1){	
				tree[v] = MatrixOne;
			} else {
				tree[v] = MatrixZero;
			}
			return;
		}
		
		int m = (l+r) >> 1;
		
		if(pos <= m){
			update(2*v+1, l, m, pos, val);
		} else {
			update(2*v+2, m+1, r, pos, val);
		}
		
		if(m+1 > r){
			tree[v] = tree[2*v+1];
			return;
		}
		
		tree[v] = (tree[2*v+1] * tree[2*v+2]);
	}
	
	ll query(){
		Matrix ans = tree[0];
		ans = (ans * MatrixInitial);
		return (ans.a[0][0] + ans.a[1][0]) % mod;
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	tree.build(0, 0, n-1, s);
	
	while(q--){
		int pos;
		char c;
		cin >> pos >> c;
		
		pos--;
		
		int val = 2;
		if(c == '1') val = 1;
		else if(c == '0') val = 0;
		
		tree.update(0, 0, n-1, pos, val);
		
		cout << tree.query() << "\n";
	}
	
    return 0;
}

