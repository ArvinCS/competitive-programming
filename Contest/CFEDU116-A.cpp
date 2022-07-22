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
		
		int a = 0, b = 0;
		for(int x=0;x+1<s.length();x++){
			if(s[x] == 'a' && s[x+1] == 'b'){
				a++;
			} else if(s[x] == 'b' && s[x+1] == 'a'){
				b++;
			}
		}
		
		if(a > b){
			if(s[s.length()-1] == 'b'){
				s[s.length()-1] = 'a';
			}
		} else if(a < b){
			if(s[s.length()-1] == 'a'){
				s[s.length()-1] = 'b';
			}
		}
		
		cout << s << "\n";
	}
	
    return 0;
}

