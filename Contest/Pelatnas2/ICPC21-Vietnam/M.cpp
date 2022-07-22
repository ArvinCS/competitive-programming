#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	if(n == 1){
		cout << "1\n";
		cout << "1\n";
		return 0;
	}
	
	cout << 2*n-1 << "\n";
	
	int cur = 2;
	
	int grid[2*n][n];
	for(int x=1;x<=n;x++){
		grid[x][0] = 1;
		cout << 1;
		for(int y=1;y<n;y++){
			grid[x][y] = cur;
			cout << " " << cur++;
		}
		cout << "\n";
	}
	for(int x=n+1;x<=2*n-1;x++){
		cout << grid[1][1];
		for(int y=1;y<n;y++){
			cout << " " << grid[y+1][x-n];
		}
		cout << "\n";
	}
	return 0;
}
