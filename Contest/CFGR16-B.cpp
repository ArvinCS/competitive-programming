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
		string s;
		cin >> s;
		
		bool one = false, zero = false;
		int cnt = 0;
		for(int x=0;x<s.length();x++){
			if(s[x] == '0' && (x == 0 || s[x-1] == '1')){
				cnt++;
			}
			
			if(s[x] == '0'){
				zero = true;
			} else {
				one = true;
			}
		}
		
		if(cnt >= 2){
			cout << "2\n";
		} else if(cnt == 1){
			cout << cnt << "\n";
		} else {
			if(zero){
				cout << "1\n";
			} else {
				cout << "0\n";
			}
		}
	}
	
    return 0;
}

