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

	us t;
	cin >> t;
	
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		
		map<int, int> mp[2];
		int v[n], h[m];
		pair<int, int> p[k];
		
		vector<pair<int, int>> s, t;
		for(int x=0;x<n;x++){
			cin >> v[x];
			mp[0][v[x]]++;
			s.push_back({v[x], k});
		}
		for(int x=0;x<m;x++){
			cin >> h[x];
			mp[1][h[x]]++;
			t.push_back({h[x], k});
		}
		for(int x=0;x<k;x++){
			cin >> p[x].first >> p[x].second;
		}
		
		ll ans = k*1ll*(k-1)/2;
		map<int, int> same[2];
		vector<int> a, b, c;
		for(int x=0;x<k;x++){
			if(mp[0][p[x].first] && mp[1][p[x].second]){
				a.push_back(x);
			} else if(mp[0][p[x].first]){
				b.push_back(x);
				t.push_back({p[x].second, x});
				same[0][p[x].first]++;
			} else {
				c.push_back(x);
				s.push_back({p[x].first, x});
				same[1][p[x].second]++;
			}
		}
		
		ans -= b.size()*1ll*c.size() + a.size()*1ll*(b.size()+c.size()) + a.size()*1ll*(a.size()-1)/2;
		
		for(auto p : same[0]){
			ans -= p.second*1ll*(p.second-1)/2;
		}
		for(auto p : same[1]){
			ans -= p.second*1ll*(p.second-1)/2;
		}
		
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		
		queue<int> q;
		map<int, int> cur;
		int cnt = 0;
		for(int x=0;x<s.size();x++){
			if(s[x].second >= k){
				while(!q.empty()){
					cnt++;
					cur[q.front()]++;
					q.pop();
				}
			} else {
				ans -= cnt-cur[p[s[x].second].second];
				q.push(p[s[x].second].second);
			}
		}
			
		cnt = 0;
		while(!q.empty()) q.pop();
		cur.clear();
		for(int x=0;x<t.size();x++){
			if(t[x].second >= k){
				while(!q.empty()){
					cnt++;
					cur[q.front()]++;
					q.pop();
				}
			} else {
				ans -= cnt-cur[p[t[x].second].first];
				q.push(p[t[x].second].first);
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

