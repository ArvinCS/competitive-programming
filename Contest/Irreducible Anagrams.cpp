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
	
	string s;
	cin >> s;
	
	int cnt[s.length()+1][26];
	fill(cnt[0], cnt[s.length()], 0);
	
	for(int x=1;x<=s.length();x++){
		for(int y=0;y<26;y++){
			cnt[x][y] = cnt[x-1][y];
		}
		cnt[x][s[x-1]-'a']++;
	}
	
	int q;
	cin >> q;
	
	for(int i=1;i<=q;i++){
		int l, r;
		cin >> l >> r;
		
		int length = r-l+1;
		if(length == 1){
			cout << "YES\n";
			continue;
		} else {
			int diff = 0;
			for(int x=0;x<26;x++){
				if(cnt[r][x]-cnt[l-1][x] > 0) diff++;
			}
			
			if(s[l-1] != s[r-1] || diff >= 3){
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

