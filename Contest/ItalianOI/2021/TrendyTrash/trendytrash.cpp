#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pulisci(int n, int m, vector<string> s) {
	int ans = 0;
	
	int row[n][2], col[m][2];
	fill(row[0], row[n], 0);
	fill(col[0], col[m], 0);
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			row[x][(s[x][y] == '1')]++;
		}
	}
	for(int y=0;y<m;y++){
		for(int x=0;x<n;x++){
			col[y][(s[x][y] == '1')]++;
		}
	}
	
	bool valid = true;
	while(valid){
		valid = false;
		for(int x=0;x<n;x++){
			if((row[x][0] == 0 && row[x][1] > 0) || (row[x][1] == 0 && row[x][0] > 0)){
				for(int y=0;y<m;y++){
					if(s[x][y] != '.'){
						row[x][(s[x][y] == '1')]--;
						col[y][(s[x][y] == '1')]--;
						s[x][y] = '.';
					}
				}
				valid = true;
			}
		}	
		for(int y=0;y<m;y++){
			if((col[y][0] == 0 && col[y][1] > 0) || (col[y][1] == 0 && col[y][0] > 0)){
				for(int x=0;x<n;x++){
					if(s[x][y] != '.'){
						row[x][(s[x][y] == '1')]--;
						col[y][(s[x][y] == '1')]--;
						s[x][y] = '.';
					}
				}
				valid = true;
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(s[x][y] != '.') ans++;
		}
	}
	return ans;
}
