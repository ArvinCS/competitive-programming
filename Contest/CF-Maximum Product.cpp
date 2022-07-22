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

vector<ll> num1, num2;
pair<string, ll> dp[22][2][2][2]; // pos, safeA, safeB, notZero, num/sum

ll len(ll x){
	ll ans = 0;
	while(x > 0){
		ans++;
		x /= 10;
	}
	return ans;
}

pair<string, ll> solve(int pos, bool notZero, bool safeA, bool safeB){
	if(pos == num2.size()){
		return {"", 1};
	}
	
	if(dp[pos][safeA][safeB][notZero].second != -1){
		return dp[pos][safeA][safeB][notZero];
	}
	
	ll low, up;
	if(safeA){
		low = 0;
	} else {
		low = num1[pos];
	}
	if(safeB){
		up = 9;
	} else {
		up = num2[pos];
	}
	
	string ans;
	ll cnt = -1;
	for(ll x=0;x<=9;x++){
		if(low <= x && x <= up){
			bool cur = notZero | x > 0;
			
			pair<string, ll> p = solve(pos+1, cur, safeA | x > num1[pos], safeB | x < num2[pos]);

			if((cur ? x : 1)*p.second > cnt){
				cnt = (cur ? x : 1)*p.second;
				ans = p.first;
				if(cur) ans.push_back('0' + x);
			}
		}
	}	

	dp[pos][safeA][safeB][notZero].first = ans;
	dp[pos][safeA][safeB][notZero].second = cnt;
	return dp[pos][safeA][safeB][notZero];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll a, b;
	cin >> a >> b;
	
	int diff = len(b)-len(a);
	while(a > 0){
		num1.push_back(a % 10);
		a /= 10;
	}
	while(b > 0){
		num2.push_back(b % 10);
		b /= 10;
	}
	
	for(int x=1;x<=diff;x++) num1.push_back(0);
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	
	for(int x=0;x<22;x++){
		for(int y=0;y<2;y++){
			for(int z=0;z<2;z++){
				for(int i=0;i<2;i++) dp[x][y][z][i].second = -1;
			}
		}
	}
	
	pair<string, ll> ans = solve(0, false, false, false);
	reverse(ans.first.begin(), ans.first.end());
	cout << ans.first << "\n";
    return 0;	
}

// Santai
// Pikirin dengan benar-benar

