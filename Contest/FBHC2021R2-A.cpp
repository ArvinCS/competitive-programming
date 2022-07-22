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
	freopen("runway_input.txt","r",stdin);
	freopen("runway_output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n, m;
		cin >> n >> m;
		
		ll s[m];
		for(int x=0;x<m;x++){
			cin >> s[x];
		}
		
		ll ans = 0;
		multiset<ll> st, st2;
		
		for(int x=0;x<m;x++){
			st2.insert(s[x]);
			st.insert(s[x]);
		}
		
		ll p[m];
		bool done[m];
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> p[y];
			}
			
			fill(done, done+m, false);
			
			for(int y=0;y<m;y++){
				if(st.count(p[y])){
					done[y] = true;
					st.erase(st.find(p[y]));
					
					auto it = st2.find(p[y]);
					if(it != st2.end()) st2.erase(it);
				}
			}
			
			for(int y=0;y<m;y++){
				if(st2.size() == 0) break;
				if(!done[y]){
					if(st2.count(p[y])){
						done[y] = true;
						st.erase(st.find(p[y]));
						st2.erase(st2.find(p[y]));
					}
				}
			}
			
			for(int y=0;y<m;y++){
				if(!done[y]){
					ans++;
				}
				st.insert(p[y]);
			}
		}
		
		cout << "Case #" << i << ": " << ans << "\n";
	}
	
    return 0;
}

