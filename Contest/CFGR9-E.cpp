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
	
	bool valid[n][n];
	fill(valid[0], valid[n], false);
	
	for(int x=n-1;x>=0;x--){
		for(int y=0;y<x;y++){
			if(a[y] > a[x]){
				valid[y][x] = true;
			}
		}
	}
	
	vector<array<int, 2>> ans;
	for(int x=n-1;x>=0;x--){
		vector<pair<int, int>> v;
		for(int y=0;y<x;y++){
			if(valid[y][x]){
				v.push_back({a[y], -y});
			}
		}
		
		if(v.empty()) continue;
		
		int sz = v.size();
		sort(v.begin(), v.end());
		
		int mn = 0;
		for(int y=0;y<v.size();y++){
			if(a[-v[y].second] > a[x]){
				mn = y;
				break;
			}
		}
		
		for(int y=0;y<v.size();y++){
			ans.push_back({-v[y].second, x});
			swap(a[-v[y].second], a[x]);
		}
	}
	
	cout << ans.size() << "\n";
	for(auto a : ans){
		cout << a[0]+1 << " " << a[1]+1 << "\n";
	}
    return 0;
}
