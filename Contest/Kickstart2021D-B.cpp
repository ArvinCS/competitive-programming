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
	
	for(us i=1;i<=t;i++){
		int n;
		cin >> n;
		
		ll c;
		cin >> c;
		
		vector<pair<ll, int>> v;
		for(int x=0;x<n;x++){
			ll l, r;
			cin >> l >> r;
			
			v.push_back({l+1, 1});
			v.push_back({r, -1});
		}
		
		sort(v.begin(), v.end());
		
		priority_queue<pair<ll, ll>> pq;
		ll prv = 0, cnt = 0, oldCnt = 0;
		for(int x=0;x<v.size();x++){
			pair<ll, int> p = v[x];
			if(p.second == 1){
				if(cnt == 0){
					prv = p.first;
				}
				cnt++;
				
//				cout << p.first << " " << prv << " " << cnt << " " << oldCnt << "\n";
				pq.push({cnt-1, p.first-prv});
				prv = p.first;
				oldCnt = cnt;
			} else {
				cnt--;
				if(x+1 < v.size() && p == v[x+1]){
					continue;
				}
				
//				cout << p.first << " " << prv << " " << oldCnt << "\n";
				pq.push({oldCnt, p.first-prv});
				oldCnt = cnt;
				prv = p.first;
			}
		}
		
		ll ans = n;
		while(c > 0 && !pq.empty()){
			pair<ll, ll> p = pq.top();
			pq.pop();
			
			ans += min(p.second, c)*p.first;
			c -= min(p.second, c);
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

