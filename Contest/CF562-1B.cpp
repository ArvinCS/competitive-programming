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
	
	ll len = s.length();
	ll ans = 0, minRight = len;
	for(ll x=len-1;x>=0;x--){
		for(ll y=1;x<len;y++){
			if(x+y+y >= minRight) break;
			if(s[x] == s[x+y] && s[x+y] == s[x+y+y]){
				minRight = x+y+y;
				break;
			}
		}
		ans += len-minRight;
	}
	
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

