#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	string new_s;
	for(int x=0;x<n;x++){
		if(s[x] == 'A'){
			new_s.push_back('B');
			new_s.push_back('B');
		} else {
			new_s.push_back(s[x]);
		}
	}
	
	swap(s, new_s);
	
	string ans;
	for(int x=0;x<s.length();x++){
		if(x+1 < s.length() && s[x] == 'B' && s[x+1] == 'B'){
			ans.push_back('A');
			x++;
		} else {
			ans.push_back(s[x]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

