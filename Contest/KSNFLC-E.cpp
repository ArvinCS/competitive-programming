#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	int k;
	cin >> n >> k;
	
	vector<pair<int, int>> p;
	for(int x=0;x<k;x++){
		int a, b;
		cin >> a >> b;
		
		p.push_back({a, b});
	}
	
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	k = p.size();
	
	ll ans = n*n;
	map<int, int> mp1, mp2;
	for(int x=0;x<k;x++){
		mp1[(p[x].first-p[x].second)]++;
		mp2[(n-p[x].first-p[x].second+1)]++;	
	}
	
	vector<int> left[2], right[2];
	for(auto p : mp1){
		left[abs(p.first)%2].push_back(p.first);
		ans -= (n-abs(p.first));
	}
	for(auto p : mp2){
		right[abs(p.first)%2].push_back(p.first);
		ans -= (n-abs(p.first));
	}
	
	if(n % 2 == 0){
		for(auto pos : right[0]){
			int idx1 = lower_bound(left[1].begin(), left[1].end(), -(n-1)+abs(pos)) - left[1].begin();
			int idx2 = lower_bound(left[1].begin(), left[1].end(), (n-1)-abs(pos)+1) - left[1].begin();
			
			ans += idx2-idx1;
		}
		for(auto pos : right[1]){
			int idx1 = lower_bound(left[0].begin(), left[0].end(), -(n-1)+abs(pos)) - left[0].begin();
			int idx2 = lower_bound(left[0].begin(), left[0].end(), (n-1)-abs(pos)+1) - left[0].begin();
			
			ans += idx2-idx1;
		}
	} else {		
		for(auto pos : right[0]){
			int idx1 = lower_bound(left[0].begin(), left[0].end(), -(n-1)+abs(pos)) - left[0].begin();
			int idx2 = lower_bound(left[0].begin(), left[0].end(), (n-1)-abs(pos)+1) - left[0].begin();
			
			ans += idx2-idx1;
		}
		for(auto pos : right[1]){
			int idx1 = lower_bound(left[1].begin(), left[1].end(), -(n-1)+abs(pos)) - left[1].begin();
			int idx2 = lower_bound(left[1].begin(), left[1].end(), (n-1)-abs(pos)+1) - left[1].begin();
			
			ans += idx2-idx1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
