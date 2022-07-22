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

ll dp[2005][2005][2][2];
ll m, d;
string a, b;

ll solve(ll pos, ll remain, bool safeA, bool safeB){
//	cout << pos << ": " << num << "\n";	
	if(pos == b.length()){
		if(remain == 0){
//			cout << num << "\n";
			return 1;
		}
		return 0;
	}
		
	if(dp[pos][remain][safeA][safeB] != -1) return dp[pos][remain][safeA][safeB];
	
	int low, up;
	if(safeA){
		low = 0;
	} else {
		low = a[pos] - '0';
	}
	if(safeB){
		up = 9;
	} else {
		up = b[pos] - '0';
	}
	
	ll ans = 0;
	for(int x=low;x<=up;x++){
		if(pos % 2 == 0 && x == d) continue;
		if(pos % 2 == 1 && x != d) continue;
		ans += solve(pos+1, (remain * 10 + x) % m, safeA | x > low, safeB | x < up);
		ans %= mod;
	}
	return dp[pos][remain][safeA][safeB] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> m >> d >> a >> b;

	fill(dp[0][0][0], dp[b.length()][m][2], -1);
	
	cout << solve(0, 0, false, false) % mod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

