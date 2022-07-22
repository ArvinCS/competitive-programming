#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	
	char table[h][w];
	fill(table[0], table[h], '.');
	
	for(int x=0;x<n;x++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		table[--tmp1][--tmp2] = 'o';	
	}
	
	for(int x=0;x<m;x++){
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		table[--tmp1][--tmp2] = 'x';	
	}
	
	bool ans[h][w];
	fill(ans[0], ans[h], false);
	
	for(int x=0;x<h;x++){
		bool valid = false;
		for(int y=0;y<w;y++){
			if(table[x][y] == 'o') valid = true;
			else if(table[x][y] == 'x') valid = false;
			
			if(valid) ans[x][y] = true;
		}
		valid = false;
		for(int y=w-1;y>=0;y--){
			if(table[x][y] == 'o') valid = true;
			else if(table[x][y] == 'x') valid = false;
			
			if(valid) ans[x][y] = true;
		}
	}
	
	for(int x=0;x<w;x++){
		bool valid = false;
		for(int y=0;y<h;y++){
			if(table[y][x] == 'o') valid = true;
			else if(table[y][x] == 'x') valid = false;
			
			if(valid) ans[y][x] = true;
		}
		valid = false;
		for(int y=h-1;y>=0;y--){
			if(table[y][x] == 'o') valid = true;
			else if(table[y][x] == 'x') valid = false;
			
			if(valid) ans[y][x] = true;
		}
	}
	
	int total = 0;
	for(int x=0;x<h;x++){
		for(int y=0;y<w;y++){
			if(ans[x][y]) total++;
		}
	}
	
	cout << total << "\n";
    return 0;
}

