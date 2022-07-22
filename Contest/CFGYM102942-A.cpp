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
		cin >> s;
		
		int cur = 0;
		for(int x=0;x<n;x++){
			if(s[x] == '0'){
				cur++;
			} else {
				cur--;
			}
			cur = (cur+4)%4;
		}
				
		if(cur == 0){
			cout << "E\n";
		} else if(cur == 1){
			cout << "S\n";
		} else if(cur == 2){
			cout << "W\n";
		} else {
			cout << "N\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

