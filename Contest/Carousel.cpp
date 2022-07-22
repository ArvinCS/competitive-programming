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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		set<int> st;
		unordered_map<int, int> mp;
		int type[n];
		for(int x=0;x<n;x++){
			cin >> type[x];
			st.insert(type[x]);
		}

		int cnt = 0;
		for(set<int>::iterator it=st.begin();it != st.end();it++){
			mp[*it] = cnt++;
		}
			
		for(int x=0;x<n;x++){
			type[x] = mp[type[x]];
		}
		
		int ans[n], k = 0;
		fill(ans, ans+n, -1);
		
		if(cnt == 1){
			k = 1;
			fill(ans, ans+n, 1);
		} else {
			k = 2;
			for(int x=0;x<n;x++){
				ans[x] = (x % 2 == 0 ? 1 : 2);
			}
			if(n&1){
				bool same = false;
				for(int x=1;x<n;x++){
					if(type[x] == type[x-1]){
						same = true;
						
						int cur = 2;
						for(int y=x+1;y<n;y++){
							ans[y] = cur;
							cur++;
							if(cur > 2) cur = 1;
						}
						cur = 2;
						for(int y=x-2;y>=0;y--){
							ans[y] = cur;
							cur++;
							if(cur > 2) cur = 1;
						}
						ans[x] = ans[x-1] = 1;
						break;
					}
				}
				
				if(!same && type[n-1] != type[0]){
					k = 3;
					ans[n-1] = 3;
				}
			}
		}
		
		cout << k << "\n";
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

