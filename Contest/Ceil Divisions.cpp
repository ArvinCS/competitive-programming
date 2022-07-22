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
		int n;
		cin >> n;
		
		vector<pair<int, int>> ans;
		if(n <= 8){
			for(int x=3;x<n;x++){
				ans.push_back({x, n});
			}
			for(int x=0;x<(n+1)/2;x++){
				ans.push_back({n, 2});
			}
		} else {
			
		}
		
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

