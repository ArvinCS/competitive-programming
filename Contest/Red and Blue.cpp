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
		cin >> n;
		
		int r[n];
		for(int x=0;x<n;x++) cin >> r[x];
		
		cin >> m;
		int b[m];
		for(int x=0;x<m;x++) cin >> b[x];
		
		for(int x=1;x<n;x++){
			r[x] += r[x-1];
		}
		for(int x=1;x<m;x++){
			b[x] += b[x-1];
		}
		
		int ans = 0;
		for(int x=0;x<n;x++){
			int firstR = r[x];
			for(int y=0;y<m;y++){
				int firstB = b[y];
				ans = max(ans, max(max(firstR, firstB), firstR+firstB));
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

