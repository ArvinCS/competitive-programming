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
	
	pair<int, int> a[n];
	for(int x=0;x<n;x++){
		cin >> a[x].first;
		a[x].second = x;
	}
	
	sort(a, a+n);
	
	int mn[550];
	fill(mn, mn+550, n+1);
	
	mn[0] = -1;
	
	for(int x=0;x<n;x++){
		for(int y=0;y<550;y++){
			if(mn[y] < a[x].second){
				mn[y^a[x].first] = min(mn[y^a[x].first], a[x].second);
			}
		}
	}
	
	vector<int> ans;
	for(int x=0;x<550;x++){
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

