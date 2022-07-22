#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<int, int> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	string s;
	cin >> s;
	
	bool valid = false;
	map<int, int> mp[2];
	for(int x=0;x<n;x++){		
		if(s[x] == 'L'){
			auto it = mp[1].find(p[x].second);
			if(it != mp[1].end()){
				if(p[x].first >= (*it).second){
					valid = true;
				}
			}
			
			it = mp[0].find(p[x].second);
			
			if(it == mp[0].end()){
				mp[0][p[x].second] = p[x].first;
			} else {
				mp[0][p[x].second] = max((*it).second, p[x].first);
			}
		} else {
			auto it = mp[0].find(p[x].second);
			if(it != mp[0].end()){
				if(p[x].first <= (*it).second){
					valid = true;
				}
			}
			
			it = mp[1].find(p[x].second);
			
			if(it == mp[1].end()){
				mp[1][p[x].second] = p[x].first;
			} else {
				mp[1][p[x].second] = min((*it).second, p[x].first);
			}
		}
	}
	
	cout << (valid ? "Yes" : "No") << "\n";
    return 0;
}

