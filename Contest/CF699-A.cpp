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
		int n, m;
		cin >> n >> m;
		
		int a = 0, b = 0, c = 0, d = 0;
		
		string s;
		cin >> s;
		
		for(int x=0;x<s.length();x++){
			if(s[x] == 'U'){
				a++;
			} else if(s[x] == 'D'){
				b++;
			} else if(s[x] == 'R'){
				c++;
			} else { // L
				d++;
			}
		}
		
		bool tmp1 = (n <= 0 && d >= abs(n)) || (n >= 0 && c >= n);
		bool tmp2 = (m <= 0 && b >= abs(m)) || (m >= 0 && a >= m);
//		cout << tmp1 << " " << tmp2 << "\n";
		if(tmp1 && tmp2){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

