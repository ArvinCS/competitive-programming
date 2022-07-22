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

ll dp[12][90][90][2]; // length, num, sum digits, safe
vector<int> v;
int a, b, k;

ll solve(int pos, int num, int sum, bool safe){
	if(pos == v.size()){
		if(num == 0 && sum == 0) return 1;
		return 0;
	}
	
	if(dp[pos][num][sum][safe] != -1) return dp[pos][num][sum][safe];
	
	ll ans = 0;
	int limit;
	
	if(safe){
		limit = 9;
	} else {
		limit = v[pos];
	}
	
	for(int x=0;x<=limit;x++){
		ans += solve(pos+1, (num*10+x)%k, (sum+x)%k, safe || x < limit);
	}
	
	return dp[pos][num][sum][safe] = ans;
}

ll find(ll x){
	v.clear();
	while(x > 0){
		v.push_back(x % 10);
		x /= 10;
	}
	reverse(v.begin(), v.end());	
	
	fill(dp[0][0][0], dp[v.size()][90][90], -1);
	return solve(0, 0, 0, false);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	for(us i=1;i<=t;i++){
		cin >> a >> b >> k;
		
		cout << "Case " << i << ": ";
		if(k > 83){
			cout << 0;
		} else {
			cout << find(b) - find(a-1);
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

