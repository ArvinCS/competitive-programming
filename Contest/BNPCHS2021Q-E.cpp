#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

string s;
struct SegTree{
	vector<vector<ll>> tree; // start & end with x,z z,x x,x z,z
	ll cnt[2]; // end with x z
	
	void resize(int n){
		tree = vector<vector<ll>>(4*n, vector<ll>(4, 0));
	}
	
	void reset(){
		cnt[0] = cnt[1] = 0;
	}
	
	ll get(){
		return (cnt[0]+cnt[1]) % mod;
	}
	
	void merge(int i){
		tree[i][0] = ((tree[i*2+1][0]) * tree[i*2+2][0] % mod + (tree[i*2+1][2]) * tree[i*2+2][3] % mod + tree[i*2+1][0] + tree[i*2+2][0]) % mod; // (x,z)*x,z + (x,x)*z,z + nonjoin part
		tree[i][1] = ((tree[i*2+1][1]) * tree[i*2+2][1] % mod + (tree[i*2+1][3]) * tree[i*2+2][2] % mod + tree[i*2+1][1] + tree[i*2+2][1]) % mod; // (z,x)*z,x + (z,z)*x,x + nonjoin part
		tree[i][2] = ((tree[i*2+1][2]) * tree[i*2+2][1] % mod + (tree[i*2+1][0]) * tree[i*2+2][2] % mod + tree[i*2+1][2] + tree[i*2+2][2]) % mod; // (x,x)*z,x + nonjoin part
		tree[i][3] = ((tree[i*2+1][3]) * tree[i*2+2][0] % mod + (tree[i*2+1][1]) * tree[i*2+2][3] % mod + tree[i*2+1][3] + tree[i*2+2][3]) % mod; // (z,z)*x,z + nonjoin part
	}
	
	void build(int i, int l, int r){
		if(l > r) return;
		if(l == r){
			tree[i][0] = 0;
			tree[i][1] = 0;
			tree[i][2] = (s[l] == 'x');
			tree[i][3] = (s[l] == 'z');
			return;
		}
		
		int m = (l+r) >> 1;
		build(i*2+1, l, m);
		build(i*2+2, m+1, r);
		
		merge(i);
	}
	
	void update(int i, int l, int r, int pos){
		if(l > pos || r < pos) return;
		if(l == r){
			tree[i][0] = 0;
			tree[i][1] = 0;
			tree[i][2] = (s[l] == 'x');
			tree[i][3] = (s[l] == 'z');
			return;
		}
		
		int m = (l+r) >> 1;
		
		if(pos <= m) update(i*2+1, l, m, pos);
		else update(i*2+2, m+1, r, pos);
		
		merge(i);
	}
	
	void query(int i, int curL, int curR, int l, int r){
		if(curR < l || curL > r) return;
		if(l <= curL && curR <= r){
			ll tmp1 = (cnt[1]*(tree[i][2]) % mod + cnt[0]*(tree[i][1]) % mod + tree[i][1] + tree[i][2]) % mod; // z*(x,x) + x*(z,x) + z,x + x,x
			ll tmp2 = (cnt[0]*(tree[i][3]) % mod + cnt[1]*(tree[i][0]) % mod + tree[i][0] + tree[i][3]) % mod; // x*(z,z) + z*(x,z) + x,z + z,z
			
			cnt[0] += tmp1;
			cnt[0] %= mod;
			cnt[1] += tmp2;
			cnt[1] %= mod;
			return;
		}
		
		int curM = (curL+curR) >> 1;
		if(curL <= curM) query(i*2+1, curL, curM, l, r);
		if(curM+1 <= curR) query(i*2+2, curM+1, curR, l, r);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	SegTree seg;
	int q;
	cin >> s >> q;
	
	int n = s.length();
	seg.resize(n+1);
	seg.build(0, 0, n-1);
	
	while(q--){
		char t;
		cin >> t;
		
		if(t == 'Q'){
			int l , r;
			cin >> l >> r;
			
			l--; r--;
			seg.reset();
			seg.query(0, 0, n-1, l, r);
			
			cout << seg.get() << "\n";
		} else {
			int p;
			cin >> p;
			
			p--;
			if(s[p] == 'x'){
				s[p] = 'z'; // turn into z
			} else {
				s[p] = 'x'; // turn into x
			}
			seg.update(0, 0, n-1, p);
		}
	}

    return 0;
}

