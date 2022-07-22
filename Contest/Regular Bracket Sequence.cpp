#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int open = 0, close = 0;
		for(int x=0;x<s.length();x++){
			if(s[x] == '('){
				open = x;
			} else if(s[x] == ')') {
				close = x;
			}
		}
		
		if(s.length() % 2 == 0 && close > 0 && open < s.length()-1){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

