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
		short n;
		cin >> n;
		
		string s;
		cin >> s;
		
		short cnt = 0;
		for(short x=n-1;x>=0;x--){
			if(s[x] == ')') cnt++;
			else break;
		}
		
		if(cnt > n/2){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

