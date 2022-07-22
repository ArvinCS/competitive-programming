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

bool intersect(pair<int, int> a, pair<int, int> b){
	return (a.first <= b.first && a.second >= b.first) || (b.first <= a.first && b.second >= a.first);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		pair<int, int> data[n];
		vector<int> l, r;
		for(int x=0;x<n;x++){
			cin >> data[x].first >> data[x].second;
			l.push_back(data[x].first);
			r.push_back(data[x].second);
		}
		
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		
		int ans = inf_int;		
		for(int x=0;x<n;x++){
			int left = lower_bound(r.begin(), r.end(), data[x].first) - r.begin();
			int right = upper_bound(l.begin(), l.end(), data[x].second) - l.begin();

			ans = min(ans, left+(n-right));
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

