#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		int l, r;
		cin >> l >> r;
		
		v.push_back({l, 1});
		v.push_back({r, -1});
	}
	
	sort(v.begin(), v.end());
	
	int ans = 0, cur = 0;
	for(int x=0;x<v.size();x++){
		cur += v[x].second;
		ans = max(ans, cur);
	}
	
	cout << ans << "\n";
    return 0;
}

