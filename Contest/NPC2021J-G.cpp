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
	
	map<ll, vector<ll>> mp;
	for(int x=0;x<n;x++){
		ll c, k;
		cin >> c >> k;
		
		mp[c-1].push_back(k);
	}

	ll ans = 0;
	
	vector<ll> v;
	for(auto p : mp){
		sort(p.second.begin(), p.second.end());
		v.push_back(p.second[0]);
		
		for(int y=1;y<p.second.size();y++){
			ans += mp.size() * 1ll * p.second[y];
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int x=0;x<v.size();x++){
		ans += (x+1) * 1ll * v[x];
	}
	
	if(ans >= m){
		cout << "YA\n";
	} else {
		cout << "TIDAK\n";
	}
    return 0;
}

