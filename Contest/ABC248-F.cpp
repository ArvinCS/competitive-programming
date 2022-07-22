#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll mod;
	cin >> n >> mod;
	
	int m = 3*n-2;
	
	ll table[n+1][m+1][2];
	fill(*table[0], *table[n+1], 0);
	
	table[0][1][1] = table[0][0][0] = 1;
	for(int x=1;x<n;x++){
		for(int y=0;y<=m;y++){
			if(y+1 <= m){
				table[x][y+1][0] += 2*table[x-1][y][1];
				table[x][y+1][0] %= mod;
			}
			if(y+2 <= m){
				table[x][y+2][0] += table[x-1][y][0];
				table[x][y+2][0] %= mod;
			}
			if(y+2 <= m){
				table[x][y+2][1] += 3*table[x-1][y][1];
				table[x][y+2][1] %= mod;
			}
			if(y+3 <= m){
				table[x][y+3][1] += table[x-1][y][1];
				table[x][y+3][1] %= mod;
			}
			if(y+3 <= m){
				table[x][y+3][1] += table[x-1][y][0];
				table[x][y+3][1] %= mod;
			}
		}
	}
	
	for(int x=1;x<n;x++){
		if(x > 1) cout << " ";
		cout << table[n-1][m-x][1];
	}
	cout << "\n";
    return 0;
}

