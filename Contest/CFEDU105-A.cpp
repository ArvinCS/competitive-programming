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

const string t = "ABC";

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
		int start = 0;
		if(s[0] == 'B'){
			start = 1;
		} else if(s[0] == 'C'){
			start = 2;
		}
		
		int cnt[3];
		fill(cnt, cnt+3, 0);
		
		bool ans = false;
		for(int x=0;x<3;x++){
			bool possible = true;
			int cnt = 0;
			for(int y=0;y<n;y++){
				int c = (s[y] - 'A');
				if(c == start || c == x){
					cnt++;
				} else {
					cnt--;
				}
				if(cnt < 0){
					possible = false;
					break;
				}
			}
			if(cnt == 0) ans = ans | possible;
		}
		
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

