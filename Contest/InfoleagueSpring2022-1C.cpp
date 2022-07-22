#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6;
const ll mod = 1e9 + 7;

struct SegmentTree {
	ll tree[2*maxN];
	
	void reset(){
		fill(tree, tree+2*maxN, 1);
	}
	
	void update(int pos, ll val){
		pos += maxN;
		
		tree[pos] += val;
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = (tree[x] * tree[x^1]) % mod;
		}
	}
	
	ll query(int left, int right){
		ll ans = 1;
		
		for(left += maxN, right += maxN; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans *= tree[left++];
				ans %= mod;
			}
			if(right&1){
				ans *= tree[--right];
				ans %= mod;
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
	
	int n, q;
	cin >> n >> q;
	
	vector<int> v;
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		v.push_back(a[x]);
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	vector<array<int, 5>> w;
	for(int x=0;x<q;x++){
		char c;
		cin >> c;
		
		if(c == '!'){
			int x, y;
			cin >> x >> y;
			
			w.push_back({0, x, y, 0, 0});
			v.push_back(x);
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			
			w.push_back({1, x1, y1, x2, y2});
			v.push_back(x1);
			v.push_back(x2);
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	tree.reset();
	
	set<int> st[v.size()];

	for(int x=0;x<n;x++){
		int new_x = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
		
		st[new_x].insert(b[x]);
		tree.update(new_x, 1);
	}
	
	for(int i=0;i<q;i++){
		if(w[i][0] == 0){
			int x = w[i][1], y = w[i][2];
			
			int new_x = lower_bound(v.begin(), v.end(), x) - v.begin();
			auto it = st[new_x].find(y);
			if(it != st[new_x].end()){
				tree.update(new_x, -1);
				st[new_x].erase(y);
			} else {
				tree.update(new_x, 1);
				st[new_x].insert(y);
			}
		} else {
			int x1 = w[i][1], y1 = w[i][2];
			int x2 = w[i][3], y2 = w[i][4];
						
			if(x1 >= x2){
				cout << (x1 == x2 && y1 == y2) << "\n";
				continue;
			}
			
			int new_x1 = lower_bound(v.begin(), v.end(), x1) - v.begin();
			int new_x2 = lower_bound(v.begin(), v.end(), x2) - v.begin();
			
			cout << tree.query(new_x1+1, new_x2) << "\n";
		}
	}
	
    return 0;
}

