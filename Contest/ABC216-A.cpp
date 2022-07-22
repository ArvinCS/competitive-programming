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
	
	string ans;
	bool dot = false;
	for(int x=0;x<s.length();x++){
		if(s[x] == '.'){
			dot = true;
			continue;
		}
		
		if(dot){
			if(s[x] <= '2'){
				ans.push_back('-');
			} else if(s[x] >= '7'){
				ans.push_back('+');
			}
		} else {
			ans.push_back(s[x]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

