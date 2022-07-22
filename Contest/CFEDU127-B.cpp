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
		
		int p[n];
		for(int x=0;x<n;x++){
			cin >> p[x];
		}
		
		bool table[n][3];
		fill(table[0], table[n], false);
		
		for(int y=0;y<3;y++) table[0][y] = true;
		for(int x=1;x<n;x++){
			// y = 0
			if(p[x-1] == p[x]-1){
				table[x][0] |= table[x-1][0];
			} else if(p[x-1] == p[x]-2){
				table[x][0] |= table[x-1][1];
			} else if(p[x-1] == p[x]-3){
				table[x][0] |= table[x-1][2];
			}
			
			// y = 1
			if(p[x-1] == p[x]-1){
				table[x][1] |= table[x-1][1];
			} else if(p[x-1] == p[x]-2){
				table[x][1] |= table[x-1][2];
			}
			
			// y = 2
			if(p[x-1] == p[x]-1){
				table[x][2] |= table[x-1][2];
			}
		}
		
		bool possible = false;
		for(int y=0;y<3;y++) possible |= table[n-1][y];
		cout << (possible ? "YES" : "NO") << "\n";
	}
	
    return 0;
}

