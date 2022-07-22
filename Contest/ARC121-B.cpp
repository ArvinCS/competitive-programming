#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<ll> v[3];
	for(int x=0;x<2*n;x++){
		ll val;
		char c;
		cin >> val >> c;
		
		if(c == 'R'){
			v[0].push_back(val);
		} else if(c == 'G'){
			v[1].push_back(val);
		} else if(c == 'B'){
			v[2].push_back(val);
		}
	}
	
	for(int x=0;x<3;x++) sort(v[x].begin(), v[x].end());
	
	if(v[1].size() % 2 == 0){
		swap(v[0], v[1]);
	}
	if(v[2].size() % 2 == 0){
		swap(v[0], v[2]);
	}
	
	ll ans = 1e18;
	if(v[1].size() % 2 == 1){
		for(int x=0;x<v[1].size();x++){
			auto it = lower_bound(v[2].begin(), v[2].end(), v[1][x]);
			
			if(it != v[2].end()){
				ans = min(ans, abs(*it-v[1][x]));
			}
			if(it != v[2].begin()){
				it--;
				ans = min(ans, abs(*it-v[1][x]));
			}
		}
		
		ll prefix[v[0].size()], suffix[v[0].size()];
		for(int x=0;x<v[0].size();x++){
			auto it = lower_bound(v[1].begin(), v[1].end(), v[0][x]);
			
			ll mn = 1e18;
			if(it != v[1].end()){
				mn = min(mn, abs(*it-v[0][x]));
			}
			if(it != v[1].begin()){
				it--;
				mn = min(mn, abs(*it-v[0][x]));
			}
			
			prefix[x] = min(mn, (x > 0 ? prefix[x-1] : (ll) 1e18));
		}
		for(int x=v[0].size()-1;x>=0;x--){
			auto it = lower_bound(v[1].begin(), v[1].end(), v[0][x]);
			
			ll mn = 1e18;
			if(it != v[1].end()){
				mn = min(mn, abs(*it-v[0][x]));
			}
			if(it != v[1].begin()){
				it--;
				mn = min(mn, abs(*it-v[0][x]));
			}
			
			suffix[x] = min(mn, (x+1 < v[0].size() ? suffix[x+1] : (ll) 1e18));
		}
		
		for(int x=0;x<v[0].size();x++){
			auto it = lower_bound(v[2].begin(), v[2].end(), v[0][x]);
			
			if(it != v[2].end()){
				ans = min(ans, abs(*it-v[0][x])+min(x > 0 ? prefix[x-1] : (ll) 1e18, x+1 < v[0].size() ? suffix[x+1] : (ll) 1e18));
			}
			if(it != v[2].begin()){
				it--;
				ans = min(ans, abs(*it-v[0][x])+min(x > 0 ? prefix[x-1] : (ll) 1e18, x+1 < v[0].size() ? suffix[x+1] : (ll) 1e18));
			}
		}
	} else {
		ans = 0;
	}
	
	cout << ans << "\n";
    return 0;
}

