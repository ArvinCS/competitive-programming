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

const int maxM = 2e5 + 5;

ll table[maxM];

ll solve(ll cur, ll m){
	if(table[m-cur] != -1) return table[m-cur];
	
	if(cur+9 > m) return 2;
	return table[m-cur] = (solve(cur+9, m) + (cur+10 <= m ? solve(cur+10, m) : 1)) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(table, table+maxM, -1);
	for(int x=0;x<maxM;x++){
		table[x] = solve(0, x);
	}
	
	int t;
	cin >> t;
	
	while(t--){
		string s;
		int m;
		cin >> s >> m;
		
		int len = s.length();
		ll ans = 0;
		for(int x=0;x<len;x++){
			int digit = (s[x] - '0');
			int need = 10-digit;
			
			if(need > m){
				ans++;
				ans %= mod;
				continue;
			}
			
//			ll cur = m-need;
//			ll remain = cur%10;
			
			ans += table[m-need];
			ans %= mod;
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

