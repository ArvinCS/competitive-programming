#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n >> n;
	int m1[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++) cin >> m1[x][y];
	}
	cin >> n >> n;
	int m2[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++) cin >> m2[x][y];
	}
	
	// Horizontal
	bool identik = true;
	bool horizontal = true;
	bool vertical = true;
	bool diagonalkanan = true;
	bool diagonalkiri = true;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(m1[x][y] != m2[x][y]){
				identik = false;
			}
			if(m1[x][y] != m2[n-x-1][y]){
				horizontal = false;
			}
			if(m1[x][y] != m2[x][n-y-1]){
				vertical = false;
			}
			if(m1[x][y] != m2[y][x]){
				diagonalkanan = false;
			}
			if(m1[x][y] != m2[n-y-1][n-x-1]){
				diagonalkiri = false;
			}
		}
		if(x == n-1){
			if(identik) cout << "identik\n";
			else if(horizontal) cout << "horisontal\n";
			else if(vertical) cout << "vertikal\n";
			else if(diagonalkanan) cout << "diagonal kanan bawah\n";
			else if(diagonalkiri) cout << "diagonal kiri bawah\n";
			else cout << "tidak identik\n";
		}
	}
    return 0;
}
