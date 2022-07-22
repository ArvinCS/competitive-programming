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
	
	int q;
	cin >> q;
	
	while(q--){
		string s, t;
		cin >> s >> t;
		
		if(s.length() < t.length()){
			swap(s, t);
		}
		
		int len = (s.length()*t.length())/__gcd(s.length(), t.length());
				
		char ans[len];
		for(int x=0;x<len;x++){
			ans[x] = t[x%t.length()];
		}
		
		bool valid = true;
		for(int x=0;x<len;x++){
			if(ans[x] != s[x%s.length()] || ans[x] != t[x%t.length()]){
				valid = false;
				break;
			}
		}
		
		if(valid){
			for(int x=0;x<len;x++){
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "-1\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

