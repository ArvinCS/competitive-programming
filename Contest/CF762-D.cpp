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
		int n, m;
		cin >> m >> n;
		
		ll p[m][n];
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				cin >> p[x][y];
			}
		}
		
		ll left = 2, right = 1e9, ans = 1;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			bool mark[m];
			fill(mark, mark+m, false);
			
			bool possible = true, ok = false;
			for(int x=0;x<n;x++){
				bool found = false;
				for(int y=0;y<m;y++){
					if(p[y][x] >= mid){
						if(mark[y]){
							ok = true;
						}
						mark[y] = true;
						found = true;
					}
				}
				
				if(!found){
					possible = false;
					break;
				}
			}
			
			if(possible && (m <= n-1 || ok)){
				ans = max(ans, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

