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
		
		bool possible = true;
		set<char> st;
		for(int x=0;x<s.length();x++){
			if(s[x] >= 'A' && s[x] <= 'Z'){
				if(!st.count((s[x] - 'A' + 'a'))){
					possible = false;
					break;
				}
			} else {
				st.insert(s[x]);
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

