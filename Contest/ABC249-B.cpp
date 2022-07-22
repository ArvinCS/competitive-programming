#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());
	
	bool valid = true;
	bool low = false, up = false;
	for(int x=0;x<s.length();x++){
		if(x > 0 && s[x] == s[x-1]){
			valid = false;
		}
		if(s[x] >= 'A' && s[x] <= 'Z'){
			up = true;
		} else if(s[x] >= 'a' && s[x] <= 'z'){
			low = true;
		}
	}
	
	cout << (valid && up && low ? "Yes" : "No") << "\n";
    return 0;
}

