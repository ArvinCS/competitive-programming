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
		
		tuple<int, int, int> p[m];
		for(int x=0;x<m;x++){
			int a, b;
			cin >> a >> b;
			
			p[x] = make_tuple(b, a, x);
		}
		
		sort(p, p+m);
		
		ll ans = 0;
		vector<pair<int, int>> v;
		for(int x=0;x<2*n;x++){
			v.push_back({get<1>(p[x]), get<2>(p[x])+1});
			ans += get<0>(p[x]);
		}
		
		sort(v.begin(), v.end());
		
		cout << ans << "\n";
		for(int x=0;x<n;x++){
			cout << v[x].second << " " << v[2*n-x-1].second << "\n";
		}
	}
	
    return 0;
}

