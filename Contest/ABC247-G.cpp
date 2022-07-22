#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	map<pair<int, int>, int> mp;
	for(int x=0;x<n;x++){
		int a, b, c;
		cin >> a >> b >> c;
		
		mp[{a, b}] = max(mp[{a, b}], c);
	}
	
	vector<array<int, 3>> v;
	for(auto p : mp){
		v.push_back({p.first.first, p.first.second, p.second});
	}
	
	
    return 0;
}

