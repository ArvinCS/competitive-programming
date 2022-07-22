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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		
		string s;
		cin >> s;
		
		for(int x=0;x<s.length();x++){
			if(s[x] != '?'){
				if(s[x] == '0'){
					a--;
				} else {
					b--;
				}
			}
		}
		
		for(int x=0;x*2<=s.length();x++){
			int left = x, right = s.length()-1-x;
			if(left == right){
				if(s[left] == '?'){
					if(b == 0 || a&1){
						s[left] = '0';
						a--;
					} else {
						s[left] = '1';
						b--;
					}
				}
			} else {
				if(s[left] != '?' && s[right] == '?'){
					s[right] = s[left];
					if(s[left] == '0'){
						a--;
					} else {
						b--;
					}
				} else if(s[left] == '?' && s[right] != '?'){
					s[left] = s[right];
					if(s[right] == '0'){
						a--;
					} else {
						b--;
					}
				}
			}
		}
		
		for(int x=0;x*2<=s.length();x++){
			int left = x, right = s.length()-1-x;
			if(left != right){
				if(s[left] == '?' && s[right] == '?'){
					if(a > 0 && a % 2 == 0){
						s[left] = s[right] = '0';
						a -= 2;
					} else {
						s[left] = s[right] = '1';
						b -= 2;
					}
				}
			}
		}
		
		bool valid = true;
		for(int x=0;x*2<=s.length();x++){
			int left = x, right = s.length()-1-x;
			if(s[left] != s[right]){
				valid = false;
				break;
			}
		}
		
		if(a != 0 || b != 0 || !valid){
			cout << "-1\n";
			continue;
		}
		cout << s << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

