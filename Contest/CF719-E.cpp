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

const int maxN = 1e6 + 5;

ll prefix[maxN], suffix[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		string s;
		cin >> s;
		
		ll cnt = 0;
		for(ll x=0;x<n;x++){
			if(s[x] == '*') cnt++;
		}
		
		prefix[0] = 0;
		suffix[n-1] = (s[n-1] == '*' ? n-1 : 0);
		for(ll x=1;x<n;x++){
			prefix[x] = prefix[x-1] + (s[x] == '*' ? x : 0);
		}
		for(ll x=n-2;x>=0;x--){
			suffix[x] = suffix[x+1] + (s[x] == '*' ? x : 0);
		}
		
		ll ans = inf_ll;
		ll bef = 0, left = inf_int;
		if(s[0] == '*') left = 0;
		for(ll x=1;x<n;x++){
			if(cnt == 0) break;
			if(s[x-1] == '*'){
				left = min(left, x-1);
			}
			if(s[x-1] == '*' && s[x] == '.'){
				ll right = x-1;
				ll ansLeft = bef*left - (left > 0 ? prefix[left-1] : 0) - (bef*(bef+1))/2;
				
				ll cntRight = (cnt-(bef+right-left+1));
				ll ansRight = (right+1 < n ? suffix[right+1] : 0) - cntRight*right - (cntRight*(cntRight+1))/2;
								
				ans = min(ans, ansLeft+ansRight);
				bef += (right-left+1);
				left = inf_int;
			}
		}
		
		if(cnt > 0 && s[n-1] == '*'){
			left = min(left, n-1);
			ll right = n-1;
			ll ansLeft = bef*left - (left > 0 ? prefix[left-1] : 0) - (bef*(bef+1))/2;
			
			ll cntRight = (cnt-(bef+right-left+1));
			ll ansRight = (right+1 < n ? suffix[right+1] : 0) - cntRight*right - (cntRight*(cntRight+1))/2;
			
			ans = min(ans, ansLeft+ansRight);
		}
		if(cnt == 0) ans = 0;
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

