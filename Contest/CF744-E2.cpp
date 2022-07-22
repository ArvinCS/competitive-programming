#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

struct Fenwick {
	vector<int> tree;
	
	void resize(int n){
		tree = vector<int>(n, 0);
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < tree.size()){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
};

Fenwick tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> v;
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			v.push_back(a[x]);
		}
		
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		
		for(int x=0;x<n;x++){
			a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
		}
		
		tree.resize(n+5);
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			int less = tree.query(a[x]-1);
			int greater = x-tree.query(a[x]);
			
			ans += min(less, greater);
			tree.update(a[x], 1);
		}
		cout << ans << "\n";
	}

    return 0;
}

