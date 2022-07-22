#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5005;

struct SegTree {
	int tree[2*maxN];
	
	void reset(){
		fill(tree, tree+2*maxN, -1);
	}
	
	void update(int pos, int val){
		pos += maxN;
		
		tree[pos] = max(tree[pos], val);
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = max(tree[x], tree[x^1]);
		}
	}
	
	int query(int left, int right){ // [L, R)
		int ans = -1;
		
		for(left += maxN, right += maxN; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans = max(ans, tree[left--]);
			}
			if(right&1){
				ans = max(ans, tree[--right]);
			}
		}
		return ans;
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	tree.reset();
	
	ll ans = 0;
	for(int r=0;r<n;r++){
		tree.reset();
		for(int l=r;l>=0;l--){
			
		}
	}
	
	cout << ans << "\n";
	return 0;
}
