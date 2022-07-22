#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 6e5;

struct SegmentTree {
	int tree[4*maxN];
	int n;
	
	void build(int n){
		this->n = n;
		for(int x=0;x<4*n;x++){
			tree[x] = -1e9;
		}
	}
	
	void update(int pos, int val){
		pos += n;
		
		tree[pos] = max(tree[pos], val);
		
		for(int x=pos;x>1;x>>=1){
			tree[x>>1] = max(tree[x], tree[x^1]);
		}
	}
	
	int query(int left, int right){
		int ans = -1e9;
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				ans = max(ans, tree[left]);
				left++;
			}
			if(right&1){
				--right;
				ans = max(ans, tree[right]);
			}
		}
		return ans;
	}
};

SegmentTree pos, net, neg;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		ll prefix[n];
		prefix[0] = a[0];
		for(int x=1;x<n;x++){
			prefix[x] = a[x] + prefix[x-1];	
		}
		
		vector<ll> v;
		v.push_back(0);
		for(int x=0;x<n;x++){
			v.push_back(prefix[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		int m = v.size();
		pos.build(m);
		net.build(m);
		neg.build(m);
		
		int idx[n], idx2[n];
		for(int x=0;x<n;x++){
			idx[x] = lower_bound(v.begin(), v.end(), (x > 0 ? prefix[x-1] : 0)) - v.begin();
			idx2[x] = lower_bound(v.begin(), v.end(), prefix[x]) - v.begin();
		}
		
		int table[n+1];
		table[n] = 0;
		
		for(int x=n-1;x>=0;x--){
			pos.update(idx2[x], table[x+1]+x+1);
			net.update(idx2[x], table[x+1]);
			neg.update(idx2[x], table[x+1]-x-1);
			
			int r = pos.query(idx[x]+1, m);
			int mid = net.query(idx[x], idx[x]+1);
			int l = neg.query(0, idx[x]);
			
			table[x] = max({r-x, l+x, mid});
		}
		
		cout << table[0] << "\n";
	}
	
    return 0;
}

