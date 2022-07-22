#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int mx = (1 << 30);

struct SegmentTree {
	pair<int, int> tree[2*maxN];
	int n;
	
	void build(int n, int a[]){
		this->n = n;
		for(int x=0;x<n;x++){
			tree[n+x] = {a[x], x};
		}
		
		for(int x=n-1;x>=1;x--){
			tree[x] = min(tree[x<<1], tree[x<<1|1]);
		}
	}
	
	void update(int pos, int val){
		pos += n;
		
		tree[pos].first = val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = min(tree[x], tree[x^1]);
		}
	}
	
	pair<int, int> query(int left, int right){
		pair<int, int> ans = {mx, mx};
		
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans = min(ans, tree[left++]);
			}
			if(right&1){
				ans = min(ans, tree[--right]);
			}
		}
		return ans;
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		tree.build(n, a);
		
		int q;
		cin >> q;
		
		for(int x=0;x<q;x++){
			int l, r;
			cin >> l >> r;
			
			l--; r--;
			
			vector<pair<int, int>> v;
			for(int y=0;y<50;y++){
				pair<int, int> p = tree.query(l, r+1);
				
				v.push_back(p);
				
				tree.update(p.second, mx);
			}
			
			int ans = mx;
			for(int y=0;y<v.size();y++){
				for(int z=y+1;z<v.size();z++){
					ans = min(ans, v[z].first|v[y].first);
				}
			}
			
			for(int y=v.size()-1;y>=0;y--){
				tree.update(v[y].second, v[y].first);
			}
			
			cout << ans << "\n";
		}
	}
	
    return 0;
}

