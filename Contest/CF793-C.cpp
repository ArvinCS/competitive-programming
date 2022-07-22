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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		if(n == 1){
			cout << "1\n";
			continue;
		}
		
		vector<int> v[2];
		for(int x=0;x<n;x++){
			if(v[0].size() <= v[1].size()){
				if(v[0].empty() || v[0].back() != a[x]){
					v[0].push_back(a[x]);
				} else if(v[1].empty() || v[1].back() != a[x]){
					v[1].push_back(a[x]);
				}
			} else {
				if(v[1].empty() || v[1].back() != a[x]){
					v[1].push_back(a[x]);
				} else if(v[0].empty() || v[0].back() != a[x]){
					v[0].push_back(a[x]);
				}
			}
		}
		
		if(v[0].size() == v[1].size()){
			cout << v[0].size() << "\n";
			continue;
		}
		
		cout << min(v[0].size(), v[1].size())+1 << "\n";
	}
	
    return 0;
}

