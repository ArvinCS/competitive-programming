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
		
		int a[n][n];
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cin >> a[x][y];
			}
		}
		
		int ans = 0;
		for(int x=1;x<n;x++){
			for(int y=0;y<n;y++){
				int row = min(x-1, n-x-1);
				int col = min(y, n-y-1);
					
				int id = (row >= col ? row-col : col-row) % 2;
				int mx = min(row, col) % 4;
				if(row >= col){
					if(id % 2 == 1 && mx >= 1 && mx <= 2){
						ans ^= a[x][y];
//						cout << "1 ";
					} else if(id % 2 == 0 && mx >= 0 && mx <= 1){
						ans ^= a[x][y];
//						cout << "1 ";
					} else {
//						cout << "0 ";
					}
				} else if(row < col){
					if(id % 2 == 1 && mx >= 0 && mx <= 1){
						ans ^= a[x][y];
//						cout << "1 ";
					} else if(id % 2 == 0 && mx >= 0 && mx <= 1){
						ans ^= a[x][y];
//						cout << "1 ";
					} else {
//						cout << "0 ";
					}
				}
			}
//			cout << "\n";
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

