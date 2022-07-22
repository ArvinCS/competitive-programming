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
		int n, k;
		cin >> n >> k;
		
		int ground[n];
		for(int x=0;x<n;x++) cin >> ground[x];

		bool possible = true;
		
		int mx = ground[0];
		int mn = ground[0];
		for(int x=1;x<n;x++){
			mn = max(mn-k+1, ground[x]);
			mx = min(mx+k-1, ground[x]+k-1);
			
			if(mn > mx){
				possible = false;
				break;	
			}
		}
		
		if(mn > ground[n-1] || mx < ground[n-1]) possible = false;
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

