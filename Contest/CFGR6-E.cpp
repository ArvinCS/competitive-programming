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

	int n;
	cin >> n;
	
	ll a[n], ans = 0;
	for(int x=0;x<n;x++){
		cin >> a[x];
		ans += a[x];
	}

	int q;
	cin >> q;
	
	int cnt[n], pending[n];
	fill(cnt, cnt+n, 0);
	fill(pending, pending+n, 0);
	
	map<pair<int, int>, int> mp;
	while(q--){
		int s, t, u;
		cin >> s >> t >> u;
		
		s--; u--;
		if(mp.find({s, t}) != mp.end()){
			if(cnt[mp[{s, t}]] <= a[mp[{s, t}]]){
				ans++;
			}
			
			cnt[mp[{s, t}]]--;
			mp.erase({s, t});	
		}
		
		if(u >= 0){
			if(cnt[u] < a[u]){
				ans--;
			}
			
			cnt[u]++;
			mp[{s, t}] = u;
		}
		
		cout << ans << "\n";
	}
    return 0;
}

