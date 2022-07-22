#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		vector<pair<int, int>> v[n];
		vector<int> id[n];
		vector<int> w[n];
		for(int x=0;x<m;x++){
			int e, t, p;
			cin >> e >> t >> p;
			
			e--;
			v[e].push_back({t, p});
			id[e].push_back(x);
			w[e].push_back(v[e].size()-1);
		}
		
		bool possible = true;
		vector<int> ans;
		ll cur = 0;
		for(int x=0;x<n;x++){
			if(!v[x].empty()){
				ll remain = a[x]-cur;
				sort(w[x].begin(), w[x].end(), [&](int idx1, int idx2) -> bool {
					pair<int, int> a = v[x][idx1], b = v[x][idx2];
					if(a.first > remain && b.first <= remain){
						return false;
					}
					if(a.first > remain && b.first > remain){
						return true;
					}
					if(a.first <= remain && b.first > remain){
						return true;
					}
					
					return a.second*1ll*b.first > b.second*1ll*a.first;
				});
				
				ll p = 0;
				for(int y=0;y<w[x].size();y++){
					int idx = w[x][y];
					
					if(v[x][idx].first > remain) continue;
					if(p >= 100) break;
					
					cur += v[x][idx].first;
					remain -= v[x][idx].first;
					p += v[x][idx].second;
					ans.push_back(id[x][idx]);
				}
				
				if(p < 100){
					possible = false;
					break;
				}
			}
		}
		
		if(!possible){
			cout << "-1\n";
			continue;
		}
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x]+1;
		}
		cout << "\n";
	}
	
    return 0;
}

