#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int c[n], d[n], h[n];
	for(int x=0;x<n;x++){
		cin >> c[x] >> d[x] >> h[x];
	}
	
	map<ll, pair<ll, ll>> mp;
	for(int x=0;x<n;x++){
		if(mp.find(h[x]) != mp.end()){
			pair<ll, ll> p = mp[h[x]];
			
			if(p.first*c[x] < d[x]*p.second){
				mp[h[x]] = {d[x], c[x]};
			}
		} else {
			mp[h[x]] = {d[x], c[x]};
		}
	}
	
	vector<array<ll, 3>> v;
	for(auto p : mp){
		v.push_back({p.first, p.second.first, p.second.second});
	}
	
	int m;
	cin >> m;
	
	for(int x=0;x<m;x++){
		int a, b;
		cin >> a >> b;
		
		auto it = lower_bound(v.begin(), v.end(), {})
	}
    return 0;
}

