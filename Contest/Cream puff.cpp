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
	
	ll n;
	cin >> n;
	
	vector<ll> ans;
	for(ll x=1;x*x<=n;x++){
		if(n % x == 0){
			ans.push_back(x);
			if(n/x != x){
				ans.push_back(n/x);
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	for(int x=0;x<ans.size();x++){
		cout << ans[x] << "\n";
	}
	
    return 0;
}

