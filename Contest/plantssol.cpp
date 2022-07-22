#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int table[n+1][n];
	fill(table[0], table[n+1], 1e9);
	
	for(int y=0;y<n;y++){
		if(a[y] >= y){
			table[1][y] = y+1;
		}
	}
	for(int x=1;x<n;x++){
		int mn = 1e9;
		for(int y=0;y<n;y++){
			if(a[y] >= mn+y){
				table[x+1][y] = min(table[x+1][y], mn+y+1);
			}
			
			if(table[x][y]){
				mn = min(mn, table[x][y]-y);
			}
		}
		
		mn = 1e9;
		for(int y=n-1;y>=0;y--){
			if(a[y] >= mn-y){
				table[x+1][y] = min(table[x+1][y], mn-y+1);
			}
			
			if(table[x][y]){
				mn = min(mn, table[x][y]+y);
			}
		}
	}
	
	bool possible = false;
	for(int y=0;y<n;y++){
		if(table[n][y]-1 <= a[y]){
			possible = true;
		}
	}
	
	cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}

