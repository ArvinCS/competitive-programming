#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int w[n];
	for(int x=0;x<n;x++){
		cin >> w[x];
	}	
	
	vector<int> v[2];
	for(int x=0;x<n;x++){
		v[(s[x] == '1')].push_back(w[x]);
	}
	
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	
	int sz = v[1].size();
	int ans = 0;
	for(int x=0;x<v[0].size();x++){
		int idx = lower_bound(v[1].begin(), v[1].end(), v[0][x]+1) - v[1].begin();
		ans = max(ans, x+1+sz-idx);
	}
	
	for(int x=0;x<v[1].size();x++){
		int idx = lower_bound(v[0].begin(), v[0].end(), v[1][x]) - v[0].begin();
		ans = max(ans, (sz-x)+idx);
	}
	
	cout << ans << "\n";
    return 0;
}

