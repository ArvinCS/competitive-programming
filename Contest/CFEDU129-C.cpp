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
		int n;
		cin >> n;
		
		pair<int, int> a[n], b[n];
		vector<int> v, w;
		for(int x=0;x<n;x++){
			cin >> a[x].first;
			a[x].second = x;
			v.push_back(a[x].first);
		}
		for(int x=0;x<n;x++){
			cin >> b[x].first;
			b[x].second = x;
			w.push_back(b[x].first);
		}
		
		sort(v.begin(), v.end());
		sort(w.begin(), w.end());
		
		bool exist[n];
		fill(exist, exist+n, true);
		
		bool possible = true;
		int lst = -1;
		vector<pair<int, int>> ans;
		for(int x=0;x<v.size();x++){
			bool found = false;
			for(int y=x;y<n;y++){
				if(a[y].first == v[x] && b[y].first == w[x]){
					if(x != y) ans.push_back({x+1, y+1});
					swap(a[x], a[y]);
					swap(b[x], b[y]);
					found = true;
					break;
				}
			}
			if(!found) possible = false;
		}
		
		if(!possible){
			cout << "-1\n";
			continue;
		}
		
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
	}
	
    return 0;
}

