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
		
		int data[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> data[x][y];
			}
		}
		
		int cnt[n+m-1][2];
		fill(cnt[0], cnt[n+m-1], 0);
		
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cnt[x+y][data[x][y]]++;
			}	
		}
		
		int ans = 0;
		for(int x=0;x<n+m-1;x++){
			int y = n+m-2-x;
			if(x >= y) continue;
			ans += min(cnt[x][0] + cnt[y][0], cnt[x][1] + cnt[y][1]);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

