#include <bits/stdc++.h>

using namespace std;

#define ll long long

int rev(int x, int y){
	if(x&1){
		return (9-x)*10+y;
	} else {
		return (9-x)*10+(9-y);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n = 10;
	int grid[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> grid[x][y];
		}
	}
	
	int a[n*n+5];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			a[rev(x, y)] = rev(x-grid[x][y], y);
		}
	}
	
	double table[n*n+5];
	fill(table, table+n*n+5, 0);
	
	for(int x=98;x>=93;x--){
		table[x] = 6;
	}
	for(int x=92;x>=0;x--){
		table[x] = 1;
		for(int y=x+1;y<min(100, x+7);y++){
			table[x] += min(table[y], table[a[y]]) / 6;
		}
	}
	
	cout << fixed << setprecision(6) << table[0] << "\n";
    return 0;
}

