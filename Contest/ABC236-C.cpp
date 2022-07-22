#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	map<string, int> mp;
	bool ok[n];
	fill(ok, ok+n, false);
	
	for(int x=0;x<n;x++){
		string s;
		cin >> s;
		
		mp[s] = x;
	}
	
	for(int x=0;x<m;x++){
		string s;
		cin >> s;
		
		ok[mp[s]] = true;
	}
	
	for(int x=0;x<n;x++){
		cout << (ok[x] ? "Yes" : "No") << "\n";
	}
    return 0;
}

