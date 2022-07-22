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
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		
		int sum = n*(n+1)/2, len = r-l+1;
		
		int table[len];
		for(int x=0;x<len;x++){
			table[x] = (x+1);
			s -= (x+1);
		}
		
		if(s < 0){
			cout << "-1\n";
			continue;
		}
		
		for(int x=len-1;x>=0;x--){
			int bound = n-(len-1-x);
			if(s > 0){
				int left = bound-table[x];
				int more = min(s, left);
				
				s -= more;
				table[x] += more;
			}
		}
		
		if(s < 0 || s > 0){
			cout << "-1\n";
			continue;
		}
		
		set<int> st;
		int ans[n];
		fill(ans, ans+n, -1);
		
		for(int x=0;x<len;x++){
			ans[l-1+x] = table[x];
			st.insert(table[x]);
		}
		
		for(int x=0;x<n;x++){
			if(ans[x] == -1){
				for(int y=1;y<=n;y++){
					if(!st.count(y)){
						ans[x] = y;
						st.insert(y);
						break;
					}
				}
			}
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

