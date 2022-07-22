#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	pair<int, int> p[n];
	p[0] = {a[0], 0};
	
	int cur = a[0];
    for(int x=1;x<n;x++){
    	cur += a[x];
    	p[x] = {cur, x};
	}
	
	ll dist = 1e18;
	set<pair<int, int>> st;
	int pos = 0;
	for(int x=0;x<n;x++){
		while(pos < x && (p[x].second-p[pos].second)*1ll*(p[x].second-p[pos].second) >= dist){
			st.erase(p[pos++]);
		}
		
		ll d = ceil(sqrt(dist));
		auto it1 = st.lower_bound(make_pair(p[x].first-d, p[x].second));
		auto it2 = st.upper_bound(make_pair(p[x].first+d, p[x].second));
		
		for(auto it=it1;it!=it2;it++){
			ll distX = (p[x].second-(*it).second);
			ll distY = (p[x].first-(*it).first);
			
			dist = min(dist, distX*distX+distY*distY);
		}
		st.insert(p[x]);
	}
	
	cout << dist << "\n";
	return 0;
}

