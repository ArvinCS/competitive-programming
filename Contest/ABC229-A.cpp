#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 2;
	char grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y];	
		}
	}
	
	if(grid[0][0] == '#' && grid[n-1][n-1] == '#'){
		if(grid[n-1][0] == '#' || grid[0][n-1] == '#'){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	} else {
		if(grid[n-1][0] == '#' && grid[0][n-1] == '#'){
			if(grid[0][0] == '#' || grid[n-1][n-1] == '#'){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			cout << "Yes\n";
		}
	}
    return 0;
}

