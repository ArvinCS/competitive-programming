#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n, k;
	cin >> n >> k;
	
	pair<ll, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].second >> p[x].first;
	}
	
	sort(p, p+n);
	
	vector<ll> v[n+1];
	v[0].push_back(0);
	
	for(int x=0;x<n;x++){
		int cnt = 0;
		for(int y=p[x].first-1;y>=0;y--){
			sort(v[y].begin(), v[y].end());
			for(auto val : v[y]){
				v[y+1].push_back(val+p[x].second);
			}
		}
	}
	
	int cnt = 0;
	for(int y=n;y>=0;y--){
		if(cnt >= k) break;
		
		for(auto val : v[y]){
			if(cnt >= k) break;
			
			cout << y << " " << val << "\n";
			cnt++;
		}
	}
	return 0;
}
