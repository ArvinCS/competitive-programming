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
	
	string s;
	cin >> s;
	
	bool odd = false, even = false;
	for(int x=0;x<s.length();x+=2){
		if(s[x] >= 'A' && s[x] <= 'Z'){
			odd = true;
			break;
		}
	}
	
	for(int x=1;x<s.length();x+=2){
		if(s[x] >= 'a' && s[x] <= 'z'){
			even = true;
			break;
		}
	}
	
	if(!odd && !even){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

