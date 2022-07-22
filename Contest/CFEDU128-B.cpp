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
		cin >> n >> m;
		
		char grid[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> grid[x][y];
			}
		}
		
		bool possible = false;
		for(int mvX=0;mvX<n;mvX++){
			for(int mvY=0;mvY<m;mvY++){
				bool valid = true;
				for(int x=0;x<n;x++){
					for(int y=0;y<m;y++){
						if(grid[x][y] == 'R'){
							if(x-mvX < 0) valid = false;
							if(y-mvY < 0) valid = false;
						}
					}
				}
				
				if(valid && grid[mvX][mvY] == 'R'){
					possible = true;
				}
			}
		}
		
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

