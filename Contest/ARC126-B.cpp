#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e5 + 5;

pair<int, int> p[maxN];
vector<int> v[maxN];

struct SegmentTree {
	int tree[2*maxN+5];
	
	void reset(){
		fill(tree, tree+2*maxN+5, 0);
	}
	
	int query(int left, int right){
		int ans = 0;
		
		for(left += maxN, right += maxN; left < right; left >>= 1, right >>= 1){
			if(left&1) ans = max(ans, tree[left++]);
			if(right&1) ans = max(ans, tree[--right]);	
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos += maxN;
		
		tree[pos] = max(tree[pos], val);
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = max(tree[x], tree[x^1]);
		}
	}
};

SegmentTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		cin >> p[x].second >> p[x].first;
	}	
	
	sort(p, p+m);
	
	for(int x=m-1;x>=0;x--){
		v[p[x].second].push_back(p[x].first);
	}
	
	tree.reset();
	
	for(int x=1;x<=n;x++){
		for(auto r : v[x]){
			int ans = tree.query(0, r);
			tree.update(r, ans+1);
		}
	}
	
	cout << tree.query(0, maxN) << "\n";
    return 0;
}

