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

bool customSort(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ll n, m, total = 0;
		cin >> n >> m;
		
		pair<ll, int> app[n];
		for(int x=0;x<n;x++){
			cin >> app[x].first;
			total += app[x].first;
		}
		for(int x=0;x<n;x++) cin >> app[x].second;
		
		if(total < m){
			cout << "-1\n";
			continue;
		}
		
		vector<ll> ones, twos;
		for(int x=0;x<n;x++){
			if(app[x].second&1){
				ones.push_back(app[x].first);
			} else {
				twos.push_back(app[x].first);
			}
		}
		
		sort(ones.rbegin(), ones.rend());
		sort(twos.rbegin(), twos.rend());
		
		ll sum = 0;
		for(int x=0;x<twos.size();x++){
			sum += twos[x];
		}
		
		int ans = inf_int;
		int y = 0;
		for(int x=twos.size();x>=0;x--){
			while(y < ones.size() && sum < m){
				sum += ones[y++];
			}
			
			if(sum >= m){
				ans = min(ans, 2*x+y);
			}
			if(x > 0) sum -= twos[x-1];
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

