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
		string s;
		cin >> s;
		
		int last[26];
		fill(last, last+26, -1);
		
		for(int x=0;x<s.length();x++){
			last[(s[x] - 'a')] = x;
		}
		
		vector<pair<int, char>> ans;
		int mn = s.length();
		for(int x=0;x<26;x++){
			if(last[x] >= 0){
				mn = min(mn, last[x]);
			}
		}
		
		for(int x=mn;x<s.length();x++){
			cout << s[x];
		}
		cout << "\n";
	}
	
    return 0;
}

