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

bool palindrome(string s){
	for(int x=0;x<s.length()/2;x++){
		if(s[x] != s[s.length()-x-1]){
			return false;
		}
	}
	return true;
}

string rev(string s){
	string ans = s;
	for(int x=0;x<s.length()/2;x++){
		swap(ans[x], ans[s.length()-x-1]);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	unordered_set<char> st;
	for(int x=0;x<s.length()/2;x++){
		st.insert(s[x]);
		st.insert(s[s.length()-1-x]);
	}
	
	if(st.size() <= 1){
		cout << "Impossible\n";
	} else {
		bool found = false;
		
		for(int x=0;x<s.length()/2;x++){
			string tmp;
			for(int y=x+1;y<s.length();y++){
				tmp += s[y];
			}
			for(int y=0;y<=x;y++){
				tmp += s[y];
			}
			
			if(s != tmp && palindrome(tmp)){
				found = true;
				break;
			}
		}
		
		if(s.length() % 2 == 0 && (found)){
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

