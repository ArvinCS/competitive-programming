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
		
		bool even = false;
		for(int x=0;x<s.length();x++){
			if((s[x] - '0') % 2 == 0){
				even = true;
			}
		}
		
		if((s.back() - '0') % 2 == 0){
			cout << "0\n";
		} else if(even){
			cout << 1+((s.front() - '0') % 2) << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}

