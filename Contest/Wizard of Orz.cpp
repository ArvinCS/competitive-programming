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
		int n;
		cin >> n;
		
		string s;
		if(n == 1){
			s = "9";
		} else if(n == 2){
			s = "98";
		} else {
			s = "98";
			char tmp = '9';
			for(int x=2;x<n;x++){
				s += tmp++;
				
				if(tmp-1 == '9') tmp = '0';
			}
		}
		cout << s << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

