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

string s;
int pre[105][9];
bool dp[105][9];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> s;
	
	fill(dp[0], dp[s.length()], false);
	fill(pre[0], pre[s.length()], -1);
	
	dp[0][(s[0] - '0') % 8] = true;
	
	for(int x=1;x<s.length();x++){
		int digit = (s[x] - '0');
		dp[x][digit % 8] = true;
		for(int y=0;y<8;y++){
			if(dp[x-1][y]){
				dp[x][(y*10 + digit) % 8] = true;
				pre[x][(y*10 + digit) % 8] = y;
				
				dp[x][y] = true;
				pre[x][y] = y;
			}
		}
	}
	
	for(int x=0;x<s.length();x++){
		if(dp[x][0]){
			string ans = "";
			int cur = x, remain = 0;
			while(true){
				if(pre[cur][remain] != remain) ans.push_back(s[cur]);
				
				remain = pre[cur][remain];
				cur--;
				if(remain == -1) break;
			}
			
			reverse(ans.begin(), ans.end());
			
			cout << "YES\n";
			cout << ans << "\n";
			return 0;
		}
	}
	cout << "NO\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

