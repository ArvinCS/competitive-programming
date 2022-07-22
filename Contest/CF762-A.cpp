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
		
		bool possible = (s.length() % 2 == 0);
		if(possible){
			for(int x=0;x*2<s.length();x++){
				if(s[x] != s[s.length()/2+x]){
					possible = false;
				}
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

