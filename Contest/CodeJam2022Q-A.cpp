#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int r, c;
		cin >> r >> c;
		
		char grid[2*r+1][2*c+1];
		for(int x=0;x<2;x++){
			for(int y=0;y<2;y++){
				grid[x][y] = '.';
			}
		}
		for(int x=0;x<2*r+1;x+=2){
			for(int y=(x <= 1 ? 2 : 0);y<2*c+1;y++){
				grid[x][y] = (y&1 ? '-' : '+');
			}
		}
		for(int x=1;x<2*r+1;x+=2){
			for(int y=(x <= 1 ? 2 : 0);y<2*c+1;y++){
				grid[x][y] = (y&1 ? '.' : '|');
			}
		}
		
		cout << "Case #" << i << ":\n";
		for(int x=0;x<2*r+1;x++){
			for(int y=0;y<2*c+1;y++){
				cout << grid[x][y];
			}
			cout << "\n";
		}
	}
	
    return 0;
}

