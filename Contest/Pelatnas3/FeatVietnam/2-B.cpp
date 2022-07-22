#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll l, r;
	int n;
	cin >> l >> r >> n;
	
	vector<int> ans;
	for(ll m=l;m<=r;m++){
		bool ok = false;
		for(int mx=2;mx<=n;mx++){
			pair<ll, int> dp[101];
			fill(dp, dp+101, make_pair(-1e18, -1));
			
			pair<ll, int> table[mx+1][n+1];
			fill(table[0], table[mx+1], make_pair(0, 0));
			
			table[0][0] = {1, 0};
			
			for(int c=0;c<mx;c++){
				for(int a=0;a<=n;a++){
					if(table[c][a].first == 0) continue;
					
					for(int b=1;b<=n;b++){
						if(a+b > n) break;
						
						table[c+1][a+b] = max(table[c+1][a+b], {table[c][a].first*b, b});
					}
				}
			}
			
			dp[0] = {0, -1};
			for(int x=0;x<=n;x++){
				for(int y=mx;y<=n;y++){
					if(x+y > n || dp[x].first < 0) break;
					
	//				cout << y << " = " << table[mx][y].first << "\n";
					if(table[mx][y].first > 0 && dp[x].first+table[mx][y].first <= m) dp[x+y] = max(dp[x+y], {dp[x].first+table[mx][y].first, y});
				}
			}
			
			bool found = false;
			for(int x=n;x>=1;x--){
				if(dp[x].first == m){
					int w = x, y = dp[x].second;
					int cnt = 100;
					
					for(int y=0;y<n-x;y++){
						ans.push_back(100);
					}
					
					while(w > 0){
						int idx = mx;
						int cur = y;
						while(idx > 0){
							for(int x=0;x<table[idx][cur].second;x++){
								ans.push_back(cnt-(idx-1));
							}
							cur -= table[idx][cur].second;
							idx--;
						}
						
						cnt -= mx;
						
						w -= y;
						y = dp[w].second;
					}
					
					found = true;
					break;
				}
				
	//				cout << x << " -> " << get<0>(dp[x]) << "\n";
			}
			
			if(!found || ans.size() != n){
				continue;
			}
	//		assert(cur == 0);
			
			for(int x=0;x<ans.size();x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
			
			ans.clear();
			ok = true;
			break;
		}
		
		if(!ok) cout << m << "\n";
//		assert(ok);
	}
	
	return 0;	
}
