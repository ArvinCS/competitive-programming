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

string s, t;

string solve(int index, string tmp, bool checkLast){
	if(index == 3){
		bool valid = true;
		for(int x=0;x<2+checkLast;x++){
			if(tmp[x] == s[0] && tmp[(x+1)%3] == s[1]){
				valid = false;
				break;
			}
			if(tmp[x] == t[0] && tmp[(x+1)%3] == t[1]){
				valid = false;
				break;
			}
		}
		
		unordered_set<int> st;
		for(int x=0;x<3;x++){
			st.insert((tmp[x] - 'a'));
		}
//		cout << tmp << " - " << valid << " - " << st.size() << "\n";
		if(valid && st.size() == 3){
			return tmp;
		} else {
			return "";
		}
	}	
	
	string ans = solve(index+1, tmp + "a", checkLast);
	if(ans == "") ans = solve(index+1, tmp + "b", checkLast);
	if(ans == "") ans = solve(index+1, tmp + "c", checkLast);
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	cin >> s >> t;
		
	bool possible = false;
	
	string ans;
	string tmp = solve(0, "", n > 1);
	
//	cout << "-> " << tmp << "\n";
	if(tmp != ""){
		for(int x=0;x<n;x++){
			ans += tmp;
		}
		possible = true;
	} else {
		for(char x='a';x<='c';x++){
			for(char y='a';y<='c';y++){
				if(x == y) continue;
				for(char z='a';z<='c';z++){
					if(x == z || y == z) continue;
					if((x != s[0] || x != s[1]) && (y != s[0] || y != s[1]) && (z != s[0] || z != s[1])){
						if((x != t[0] || x != t[1]) && (y != t[0] || y != t[1]) && (z != t[0] || z != t[1])){
							if(!(x == s[0] && y == s[1]) && !(y == s[0] && z == s[1]) && !(x == t[0] && y == t[1]) && !(y == t[0] && z == t[1])){
								possible = true;
								tmp += x;
								tmp += y;
								tmp += z;
								break;
							}
						}
					}
				}
				if(possible) break;
			}
			if(possible) break;
		}
		
		if(possible){
			for(int i=0;i<3;i++){
				for(int x=0;x<n;x++){
					ans += tmp[i];
				}
			}
		}
	}
	
	if(possible){
		cout << "YES\n";
		cout << ans << "\n";
	} else {
		cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

