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
	
	int n;
	cin >> n;
	
	vector<pair<ll, int>> v;
	for(int x=0;x<n;x++){
		ll a, b;
		cin >> a >> b;
		
		v.push_back({a, 1});
		v.push_back({a+b, -1});
	}
	
	sort(v.begin(), v.end());
	
	ll ans[n+1];
	fill(ans, ans+n+1, 0);
	
	ll cur = 0, cnt = 0;
	for(int x=0;x<v.size();x++){
		ans[cnt] += v[x].first-cur;
		 
		if(v[x].second == -1){
			cnt--;
		} else {
			cnt++;
		}
		cur = v[x].first;
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

