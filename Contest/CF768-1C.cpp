#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

int a[maxN];

struct SegTree {
	int tree[2*maxN];
	
	void reset(){
		fill(tree, tree+2*maxN, -1e9);
	}
	
	void update(int pos, int val){
		pos += maxN;
		
		tree[pos] = max(tree[pos], val);
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = max(tree[x], tree[x^1]);
		}
	}
	
	int query(int left, int right){ // [l,r)
		int ans = -1e9;
		
		for(left += maxN, right += maxN; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans = max(ans, tree[left++]);
			}
			if(right&1){
				ans = max(ans, tree[--right]);
			}
		}
		return ans;
	}
};

SegTree l, r;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int left[n+1], right[n+1];
	fill(left, left+n+1, -1);
	fill(right, right+n+1, -1);
	
	for(int x=0;x<n;x++){
		if(left[a[x]] == -1){
			left[a[x]] = x;
		}
	}
	for(int x=n-1;x>=0;x--){
		if(right[a[x]] == -1){
			right[a[x]] = x;
		}
	}
	
	l.reset();
	r.reset();
	
	int table[n];
	fill(table, table+n, 0);
	
	for(int x=1;x<n;x++){
		if(right[a[x]] == x){
			table[x] = l.query(0, left[a[x]])+(x-left[a[x]]-(left[a[x]] != x));
			table[x] = max(table[x], r.query(left[a[x]]+1, x)+x-1);
			table[x] = max(table[x], (x-left[a[x]]-(left[a[x]] != x)));
		}
			
		l.update(x, table[x]);
		r.update(x, table[x]-x);
	}
	
	cout << table[n-1] << "\n";
    return 0;
}

