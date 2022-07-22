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

const int maxN = 2e5 + 5;

struct Fenwick {
	int tree[maxN];
	int n;
	
	void reset(int n){
		this->n = n;
		fill(tree, tree+n, 0);	
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos <= n){
			
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x] >> b[x];
			a[x] = min(a[x], n-x-1);
			b[x] = min(b[x], x);
		}
		
		vector<pair<int, int>> v;
		v.push_back({0, inf_int});
		
		int ans = 0;
		for(int x=0;x<n;x++){
			while(v.back().second == 0){
				ans = max(ans, v.back().first);
				v.pop_back();
			}
			
			pair<int, int> p = v.back();
			v.push_back({min(b[x], p.first)+1, min(p.second-1, a[x])});	
		}
		
		for(int x=0;x<v.size();x++){
			ans = max(ans, v[x].first);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

