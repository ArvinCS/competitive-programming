#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	ll d[n];
	fill(d, d+n, 0);
	
	for(int x=0;x<m;x++){
		int u, v;
		cin >> u >> v;
		
		ll val;
		cin >> val;
		
		u--; v--;
		d[u] -= val;
		d[v] += val;
 	}
	
	vector<pair<ll, int>> v, w;
	for(int x=0;x<n;x++){
		if(d[x] < 0){
			v.push_back({-d[x], x});
		} else if(d[x] > 0){
			w.push_back({d[x], x});
		}
	}
	
	sort(w.begin(), w.end());
	sort(v.begin(), v.end());
	
	vector<array<ll, 3>> ans;
	int l = 0, r = 0;
	while(l < v.size() && r < w.size()){
		while(l < v.size() && v[l].first == 0) l++;
		while(r < w.size() && w[r].first == 0) r++;
		if(l == v.size() || r == w.size()) break;
		
		ll val = min(v[l].first, w[r].first);
		ans.push_back({v[l].second+1, w[r].second+1, val});
		v[l].first -= val; w[r].first -= val;
	}
	
	cout << ans.size() << "\n";
	for(auto a : ans){
		for(int x=0;x<3;x++){
			if(x > 0) cout << " ";
			cout << a[x];
		}
		cout << "\n";
	}
    return 0;
}

