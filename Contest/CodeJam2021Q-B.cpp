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
	
	for(us i=1;i<=t;i++){
		int n, m;
		string s;
		cin >> n >> m >> s;
		
		int len = s.length();
		int table[len+1][2];
		fill(table[0], table[len+1], inf_int);
		
		if(s[0] == 'C'){
			table[0][0] = 0;
		} else if(s[0] == 'J'){
			table[0][1] = 0;
		} else {
			table[0][0] = table[0][1] = 0;
		}
		
		for(int x=1;x<len;x++){
			if(s[x] == '?'){
				table[x][0] = min(table[x-1][0], m + table[x-1][1]);
				table[x][1] = min(n + table[x-1][0], table[x-1][1]);
			} else if(s[x] == 'C'){
				table[x][0] = min(table[x-1][0], m + table[x-1][1]);
			} else if(s[x] == 'J'){
				table[x][1] = min(n + table[x-1][0], table[x-1][1]);
			}
		}

		cout << "Case #" << i << ": " << min(table[len-1][0], table[len-1][1]) << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

