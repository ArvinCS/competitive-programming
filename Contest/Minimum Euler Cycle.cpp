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
	
	us t;
	cin >> t;
	
	while(t--){
		ll n, l, r;
		cin >> n >> l >> r;
		
//		vector<int> ans;
//		for(int x=2;x<=n;x++){
//			ans.push_back(1);
//			ans.push_back(x);
//			for(int y=2;y<x;y++){
//				ans.push_back(y);
//				ans.push_back(x);
//			}
//		}
//		ans.push_back(1);
		
		vector<ll> ans;
		ull tmp = 0, cnt = 0;
		for(ll x=1;x<=n;x++){
			if(cnt > r) break;
			if(cnt+(n-x)*2 >= l){
				for(ll y=x+1;y<=n;y++){
					if(cnt > r) break;
					if(cnt+1 >= l && cnt+1 <= r) ans.push_back(x);
					if(cnt+2 >= l && cnt+2 <= r) ans.push_back(y);
					cnt += 2;
				}
			} else {
				cnt += (n-x)*2;
			}
		}
		if(r == n*(n-1)+1){
			ans.push_back(1);
		}
		
		for(ll x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

