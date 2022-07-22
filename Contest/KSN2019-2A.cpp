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

	int n, m;
	cin >> n >> m;
	
	pair<int, int> data[n];
	vector<pair<int, int>> start, end;
	for(int x=0;x<n;x++){
		int from, to;
		cin >> from >> to;
		
		data[x] = {from, to};
		start.push_back({from, x});
		end.push_back({to, x});
	}	
	
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	
	int ans[n];
	
	for(int x=0;x<n;x++){
		auto itLeft = lower_bound(end.begin(), end.end(), make_pair(data[x].first, -1));
		auto itRight = upper_bound(start.begin(), start.end(), make_pair(data[x].second, 200005));
		
		int cntLeft = (itLeft - end.begin()), cntRight = n-(itRight - start.begin());
		ans[x] = n-(cntLeft+cntRight)-1;
	}
	
	for(auto v : ans){
		cout << v << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

