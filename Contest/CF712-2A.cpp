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
	
	us t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		int n = s.length();
		
		int pos = -1;
		for(int x=n-1;x>=n/2;x--){
			if(s[x] != 'a'){
				pos = (n-1)-x;
				break;
			}
		}
		
		if(pos < 0){
			for(int x=0;x<n/2;x++){
				if(s[x] != 'a'){
					pos = (n-1)-x;
					break;
				}
			}
		}
		
		if(pos < 0){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for(int x=0;x<pos;x++){
				cout << s[x];
			}
			cout << "a";
			for(int x=pos;x<n;x++){
				cout << s[x];
			}
			cout << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

