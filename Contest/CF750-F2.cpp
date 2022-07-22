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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<int> v[8200];
	
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		v[val].push_back(x);
	}
	
	int mn[8200];
	fill(mn, mn+8200, n+1);
	
	mn[0] = -1;
	
	for(int x=0;x<8200;x++){
		for(int y=0;y<8200;y++){
			if(v[x].empty()) continue;
			
			auto it = lower_bound(v[x].begin(), v[x].end(), mn[y]+1);
			if(it != v[x].end() && mn[y] < *it){
//				cout << x << " " << y << " -> " << *it << "\n";
				mn[y^x] = min(mn[y^x], *it);
			}
		}
	}
	
	vector<int> ans;
	for(int x=0;x<8200;x++){
		if(mn[x] < n) ans.push_back(x);
	}
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

