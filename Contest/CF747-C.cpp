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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		char c;
		cin >> n >> c;
		
		string s;
		cin >> s;
		
		bool visited[n];
		fill(visited, visited+n, false);
		
		bool notlast = false;
		int best = -1;
		for(int x=1;x<=n-1;x++){
			if(s[x-1] != c) notlast = true;
			if(x > 1){
				bool valid = true;
				
				for(int y=x;y<=n;y+=x){
					if(s[y-1] != c){
						valid = false;
						break;
					}
				}
				
				if(valid){
					best = x;
				}
			}
		}
		
		vector<int> ans;
		if(s[n-1] != c){
			if(best >= 0){
				ans.push_back(best);
			} else {
				ans.push_back(n-1);
				if(notlast) ans.push_back(n);
			}
		} else {
			if(notlast){
				ans.push_back(n);
			}
		}
		
		cout << ans.size() << "\n";
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		if(ans.size() > 0) cout << "\n";
	}
	
    return 0;
}

