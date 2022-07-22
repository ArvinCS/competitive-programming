#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> v, w;
	for(int x=0;x<n;x++){
		int a, b;
		cin >> a >> b;
		
		v.push_back({a, x});
		w.push_back({b, x});
	}
	
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	
	int ans = max(v.back().first-v[1].first, w.back().first-w[1].first);
	ans = max(ans, v[v.size()-2].first-v[0].first);
	ans = max(ans, w[w.size()-2].first-w[0].first);
	
	if(v[0].second != w[0].second || v.back().second != w.back().second){
		ans = max(ans, min(v.back().first-v[0].first, w.back().first-w[0].first));
	}
	
	cout << ans << "\n";
    return 0;
}

