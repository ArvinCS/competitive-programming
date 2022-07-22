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
		
		char c;
		cin >> c;
		
		bool possible = false;
		for(int x=0;x<s.length();x++){
			if(s[x] == c){
				possible |= (x % 2 == 0 && (s.length()-x-1) % 2 == 0);
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

