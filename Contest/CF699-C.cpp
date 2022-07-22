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
		int n, m;
		cin >> n >> m;
		
		int a[n], b[n], c[m];
		unordered_set<int> st;
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
			st.insert(b[x]);
		}
		for(int x=0;x<m;x++){
			cin >> c[x];
		}
		
		bool possible = true;
		int ans[m];
		fill(ans, ans+m, -1);
		
		queue<int> painter[n];
		
		for(int x=0;x<m;x++){
			painter[c[x]-1].push(x);
		}
		
		int cnt = 0;
		for(int x=0;x<n;x++){
			if(a[x] != b[x]){
				if(painter[b[x]-1].size() == 0){
					possible = false;
					break;
				}
				
				int p = painter[b[x]-1].front();
				ans[p] = x+1;
				painter[b[x]-1].pop();
				cnt++;
			}
		}
		
		int left = ans[m-1];
		if(cnt < m){
			if(left == -1){
				for(int x=m-1;x>=0;x--){
					if(ans[x] == -1){
						for(int y=0;y<n;y++){
							if(c[x] == b[y]){
								left = y+1;
							}
						}
						break;
					}
				}
			}
			
			if(left == -1){
				possible = false;
			}
			
			for(int x=0;x<m;x++){
				if(ans[x] == -1){
					ans[x] = left;
				}
			}
		}
		
		if(possible){
			cout << "YES\n";
			for(int x=0;x<m;x++){
				if(x > 0) cout << " ";
				cout << ans[x];
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

