#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	if(s[n-2] == 'e' && s[n-1] == 'r'){
		cout << "er\n";
	} else {
		cout << "ist\n";
	}
	
    return 0;
}

