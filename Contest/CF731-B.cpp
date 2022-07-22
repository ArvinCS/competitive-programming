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
		
		int pos = -1;
		for(int x=0;x<s.length();x++){
			if(s[x] == 'a'){
				pos = x;
				break;
			}
		}
		
		int left = pos-1, right = pos+1, c = 1;
		while(left >= 0 || right < s.length()){
			bool change = false;
			if(c >= 26) break;
			if(left >= 0 && (s[left]-'a') == c){
				left--;
				c++;
				change = true;
			}
			if(c >= 26) break;
			if(right < s.length() && (s[right]-'a') == c){
				right++;
				c++;
				change = true;
			}
			
			if(!change) break;
		}
		
		if(left == -1 && right == s.length()){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

    return 0;
}

