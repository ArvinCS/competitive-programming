#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	vector<tuple<ll, int, int>> v;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			ll distX = abs(p[x].first-p[y].first);
			ll distY = abs(p[x].second-p[y].second);
			
			ll dist = distX*distX + distY*distY;
			v.push_back(make_tuple(dist, x, y));
		}
	}
	
	sort(v.begin(), v.end());
	
	int mx[n];
	fill(mx, mx+n, 0);
	
	int ans = 0;
	vector<pair<int, int>> pending;
	ll last = -1;
	for(int x=0;x<v.size();x++){
		int a = get<1>(v[x]), b = get<2>(v[x]);
		ll dist = get<0>(v[x]);
		
		if(last != dist){
			while(!pending.empty()){
				pair<int, int> p = pending.back();
				pending.pop_back();
				
				mx[p.first] = max(mx[p.first], p.second);
			}
		}
		
		if(dist < p[b].first*p[b].first+p[b].second*p[b].second) ans = max(ans, mx[a]+1);
		if(dist < p[a].first*p[a].first+p[a].second*p[a].second) ans = max(ans, mx[b]+1);
		
		pending.push_back({a, mx[b]+1});
		pending.push_back({b, mx[a]+1});
		last = dist;
	}
	
	cout << ans+1 << "\n";
    return 0;
}

