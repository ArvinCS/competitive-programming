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

ll calc(pair<ll, int> a, pair<ll, int> b){
	return (a.first-b.first)/(a.second-b.second);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		pair<ll, int> a[m];
		for(int x=0;x<m;x++){
			cin >> a[x].second;
			a[x].second--;
		}
		for(int x=0;x<m;x++){
			cin >> a[x].first;
		}
		
		pair<ll, int> b[n];
		fill(b, b+n, make_pair(-1, -1));
		for(int x=0;x<m;x++){
			b[a[x].second] = a[x];
		}
		
		ll ans[n];
		fill(ans, ans+n, inf_ll);
		
		deque<pair<ll, int>> q;
		for(int x=0;x<n;x++){
			if(b[x].first != -1){
				while(q.size() >= 1 && q.front().first+abs(q.front().second-x) >= b[x].first){
					q.pop_front();
				}
				q.push_front(b[x]);
			}
			
			if(q.size() == 0) continue;
			while(q.size() >= 2 && q.back().first+abs(q.back().second-x) >= q[q.size()-2].first+abs(q[q.size()-2].second-x)){
				q.pop_back();
			}
			
			ans[x] = q.back().first+abs(q.back().second-x);
		}
		while(!q.empty()){
			q.pop_back();
		}
		
		for(int x=n-1;x>=0;x--){
			if(b[x].first != -1){
				while(q.size() >= 1 && q.front().first+abs(q.front().second-x) >= b[x].first){
					q.pop_front();
				}
				q.push_front(b[x]);
			}
			
			if(q.size() == 0) continue;
			while(q.size() >= 2 && q.back().first+abs(q.back().second-x) >= q[q.size()-2].first+abs(q[q.size()-2].second-x)){
				q.pop_back();
			}
			
			ans[x] = min(ans[x], q.back().first+abs(q.back().second-x));
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

