#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 55;
const int maxK = 1e4 + 5;

ll dist(pair<ll, ll> a, pair<ll, ll> b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<ll, ll> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	map<tuple<ll, ll, ll>, vector<tuple<int, int, int>>> mp;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(y == x) continue;
			
			for(int z=0;z<n;z++){
				if(z == x || z == y) continue;
				if(p[x].first == p[y].first && p[y].first == p[z].first) continue;
				if(p[x].second == p[y].second && p[y].second == p[z].second) continue;
				
				mp[make_tuple(dist(p[x], p[y]), dist(p[y], p[z]), dist(p[z], p[x]))].push_back(make_tuple(x, y, z));
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			for(int z=y+1;z<n;z++){
				if(p[x].first == p[y].first && p[y].first == p[z].first) continue;
				if(p[x].second == p[y].second && p[y].second == p[z].second) continue;
				
				tuple<ll, ll, ll> t = make_tuple(dist(p[x], p[y]), dist(p[y], p[z]), dist(p[z], p[x]));
				
				for(auto t2 : mp[t]){
					if(get<0>(t2) == x || get<0>(t2) == y || get<0>(t2) == z) continue;	
					if(get<1>(t2) == x || get<1>(t2) == y || get<1>(t2) == z) continue;	
					if(get<2>(t2) == x || get<2>(t2) == y || get<2>(t2) == z) continue;	
					
					ans++;
				}
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}
