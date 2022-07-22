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

bool palindrome(int l, int r, string s){
	bool ans = true;
	for(int x=0;x<=(r-l)/2;x++){
		if(s[l+x] != s[r-x]){
			ans = false;
			break;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		bool change[s.length()];
		fill(change, change+s.length(), false);
		
		int ans = 0;
		for(int x=1;x<s.length();x++){
			bool tmp = false;
			if(s[x] == s[x-1] && !change[x-1]){
				tmp = true;
			}
			if(x > 1 && s[x] == s[x-2] && !change[x-2]){
				tmp = true;
			}
			
			change[x] = tmp;
			ans += tmp;
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

