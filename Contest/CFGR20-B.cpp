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
		int cnt = 0;
		for(int x=0;x<s.length();x++){
			if(s[x] == 'B'){
				cnt--;
			} else {
				cnt++;
			}
			
			if(cnt < 0){
				possible = false;
			}
		}
		if(s[0] != 'A' || s.back() != 'B'){
			possible = false;
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

