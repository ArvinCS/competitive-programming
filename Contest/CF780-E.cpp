#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int one = 0;
		int a[2*n][2*n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				char c;
				cin >> c;
				
				a[x][y] = (c == '1');
				one += a[x][y];
			}
			for(int y=0;y<n;y++){
				a[x][n+y] = a[x][y];
			}
		}
		for(int x=0;x<n;x++){
			for(int y=0;y<2*n;y++){
				a[n+x][y] = a[x][y];
			}
		}
		
		int ans = n*n;
		int cnt[2*n][2*n];
		for(int x=2*n-1;x>=0;x--){
			for(int y=2*n-1;y>=0;y--){
				if(x+1 < 2*n && y+1 < 2*n) cnt[x][y] = cnt[x+1][y+1];
				else cnt[x][y] = 0;
				
				cnt[x][y] += a[x][y];
				if(x+n < 2*n && y+n < 2*n){
					cnt[x][y] -= a[x+n][y+n];
				}
				if(x+n <= 2*n && y+n <= 2*n){
					ans = min(ans, one-cnt[x][y]+(n-cnt[x][y]));
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

