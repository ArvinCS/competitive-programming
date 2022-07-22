#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	int pos = 0;
	vector<pair<int, int>> v;
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int x, c;
			cin >> x >> c;
			
			v.push_back({x, c});
		} else {
			int c;
			cin >> c;
			
			ll sum = 0;
			while(c > 0){
				ll mn = min(v[pos].second, c);
				c -= mn;
				v[pos].second -= mn;
				
				sum += mn*v[pos].first;
				if(v[pos].second == 0) pos++;
			}
			
			cout << sum << "\n";
		}
	}
	
    return 0;
}

