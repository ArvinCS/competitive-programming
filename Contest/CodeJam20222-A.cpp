#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int tc=1;tc<=t;tc++){
		int n, k;
		cin >> n >> k;
		
		// if we use shortcut at some point
		// difference = c-y + r-1 + c-1 + r-2 + y-1
		// difference = c + r-1 + c-1 + r-2 - 1
		// difference = 2*c + 2*r - 6
		// difference = (2*c - 2) + (2*r - 3) - 1
		// ex. 2*3 + 2*3 - 5 = 6 + 6 - 6 = 6
		
		int dp[(n+1)/2][k+1];
		fill(dp[0], dp[(n+1)/2], -1);
		
		dp[0][0] = 0;
		for(int x=0;x<(n+1)/2-1;x++){
			int diff = 2*(n-2*x + n-2*x) - 6;
			cout << x << " -> " << diff << "\n";
			for(int y=0;y<=k;y++){
				if(dp[x][y] == -1) continue;
				if(y+diff <= k){
					dp[x+1][y+diff] = y;
				}
				dp[x+1][y] = y;
			}
		}
		
		cout << "Case #" << tc << ": ";
		
		if(dp[(n+1)/2-1][n*n-1-k] == -1){
			cout << "IMPOSSIBLE";
		} else {
			cout << "POSSIBLE";
		}
		
		cout << "\n";
	}
	
    return 0;
}

