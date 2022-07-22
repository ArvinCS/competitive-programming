#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	
	vector<ll> v;
	v.push_back(m);
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
		v.push_back(p[x].first);
		v.push_back(p[x].second);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	auto get = [&](ll val) -> int {
		return lower_bound(v.begin(), v.end(), val) - v.begin();
	};
	
	ll ans = 1e18;
	ll cost[v.size()], new_cost[v.size()];
	fill(cost, cost+v.size(), 1e18);
	
	cost[get(m)] = 0;
	
	for(int x=0;x<n;x++){
		fill(new_cost, new_cost+v.size(), 1e18);
		
		ll mn = 1e18;
		for(int y=0;y<v.size();y++){
			mn = min(mn, cost[y]-v[y]);
			new_cost[y] = min(new_cost[y], mn+v[y]);
		}
		
		mn = 1e18;
		for(int y=v.size()-1;y>=0;y--){
			mn = min(mn, cost[y]+v[y]);
			new_cost[y] = min(new_cost[y], mn-v[y]);
		}
		
		for(int y=0;y<v.size();y++){
			if(p[x].first <= v[y] && v[y] <= p[x].second) continue;
			if(v[y] < p[x].first){
				new_cost[y] += p[x].first-v[y];
			} else {
				new_cost[y] += v[y]-p[x].second;
			}
//			new_cost[y] += min(max(0ll, p[x].first-v[y]), max(0ll, v[y]-p[x].second));
		}
		
		for(int y=0;y<v.size();y++){
			cost[y] = new_cost[y];
//			cout << cost[y] << " ";
		}//cout << "\n";
	}
	
	for(int y=0;y<v.size();y++){
		ans = min(ans, cost[y]);
	}
	cout << ans << "\n";
    return 0;
}

