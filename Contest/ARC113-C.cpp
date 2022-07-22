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

	string s;
	cin >> s;
	
	int cnt[s.length()+1][26];
	fill(cnt[0], cnt[s.length()+1], 0);
	
	cnt[s.length()-1][(s.back() - 'a')]++;
	for(int x=s.length()-2;x>=0;x--){
		for(int y=0;y<=25;y++){
			cnt[x][y] = cnt[x+1][y];
		}
		cnt[x][(s[x] - 'a')]++;
	}
	
	ll ans = 0;
	char lastChar = '.';
	int lastPos = s.length();
	for(int x=s.length()-3;x>=0;x--){
		if(s[x] == s[x+1] && s[x+1] != s[x+2]){
			if(lastChar != s[x]){
				int len = s.length()-x-2;
				ans += len - cnt[x+2][(s[x] - 'a')] + cnt[lastPos][(s[x] - 'a')];
				lastChar = s[x];
				lastPos = x;
			} else {
				int len = lastPos-x-2;
				ans += len - cnt[x+2][(s[x] - 'a')] + cnt[lastPos][(s[x] - 'a')];
				lastChar = s[x];
				lastPos = x;
			}
//			cout << ans << "\n";
		}
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

