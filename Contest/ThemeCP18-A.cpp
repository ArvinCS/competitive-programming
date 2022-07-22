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

        int grid[n][m];
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                cin >> grid[x][y];
            }
        }

        int row = 0, col = 0;
        for(int x=0;x<n;x++){
            bool ok = true;
            for(int y=0;y<m;y++){
                if(grid[x][y]){
                    ok = false;
                }
            }

            if(ok) row++;
        }
        for(int y=0;y<m;y++){
            bool ok = true;
            for(int x=0;x<n;x++){
                if(grid[x][y]){
                    ok = false;
                }
            }

            if(ok) col++;
        }

        if(min(row,col) % 2 == 0){
            cout << "Vivek\n";
        } else {
            cout << "Ashish\n";
        }
    }
	
    return 0;
}

