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
		
		int mx = s.length();
		int odd = 0, even = 0;
		
		for(int x=0;x<s.length();x++){ // prioritize odd
			if(s[x] == '1'){
				if(x&1) odd++;
				else even++;
			} else if(s[x] == '?'){
				if(x&1){
					odd++;
				}
			}
			
			int remain = s.length()-1-x;
			if(x&1){
				remain = (remain+1)/2;
			} else {
				remain = remain/2;
			}
			
			if(odd > even+remain){
				mx = min(mx, x+1);
				break;
			}
		}
		
		odd = 0; even = 0;
		for(int x=0;x<s.length();x++){ // prioritize even
			if(s[x] == '1'){
				if(x&1) odd++;
				else even++;
			} else if(s[x] == '?'){
				if(x % 2 == 0){
					even++;
				}
			}
			
			int remain = s.length()-1-x;
			if(x&1){
				remain = remain/2;
			} else {
				remain = (remain+1)/2;
			}
			
			if(even > odd+remain){
				mx = min(mx, x+1);
				break;
			}
		}
		
		cout << mx << "\n";
	}
	
    return 0;
}

