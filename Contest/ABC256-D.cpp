#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		int l, r;
		cin >> l >> r;
		
		v.push_back({l, 1});
		v.push_back({r+1, 0});
	}
	
	sort(v.begin(), v.end());
	
	vector<pair<int, int>> ans;
	int cnt = 0, lst = -1;
	for(auto p : v){
		if(p.second == 0){
			cnt--;
			if(cnt == 0){
				ans.push_back({lst, p.first-1});
			}
		} else {
			if(cnt == 0){
				lst = p.first;
			}
			cnt++;
		}
	}
	
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
    return 0;
}

