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
	
	short t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		
		vector<pair<ll, ll>> v;
		for(ll x=2;x*x<=n;x++){
			int cnt = 0;
			while(n % x == 0){
				cnt++;
				n /= x;
			}
			if(cnt > 0) v.push_back({x, cnt});
		}
		if(n > 1) v.push_back({n, 1});
		
		sort(v.begin(), v.end());
		
		cout << v[0].second << v[1]<< "\n";
		vector<ll> ans;
		for(int x=0;x<v[0].second;x++) ans.push_back(v[0].first);
		
		for(int x=1;x<v.size();x++){
			for(int y=0;y<v[x].second;y++){
				ans.back() *= v[x].first;
			}
		}
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

