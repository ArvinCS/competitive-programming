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

ull table[1100][2100][4];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int x=0;x<=n;x++){
		for(int y=0;y<=2*n;y++){
			for(int z=0;z<4;z++) table[x][y][z] = 0;
		}
	}
	
	table[1][1][0] = table[1][1][3] = 1;
	table[1][2][1] = table[1][2][2] = 1;
	
	for(int x=1;x<=n-1;x++){
		for(int y=1;y<=2*x;y++){
			for(int z=0;z<4;z++) table[x+1][y][z] += table[x][y][z];
			table[x+1][y][0] += table[x][y][1] + table[x][y][2];
			table[x+1][y][3] += table[x][y][1] + table[x][y][2];
			
			table[x+1][y+1][0] += table[x][y][3];
			table[x+1][y+1][1] += table[x][y][0] + table[x][y][3];
			table[x+1][y+1][2] += table[x][y][0] + table[x][y][3];
			table[x+1][y+1][3] += table[x][y][0];
			
			table[x+1][y+2][1] += table[x][y][2];
			table[x+1][y+2][2] += table[x][y][1];
			
			for(int a=0;a<3;a++){
				for(int b=0;b<4;b++){
					table[x+1][y+a][b] %= smod;
				}
			}
		}
	}
	
	cout << (table[n][k][0] + table[n][k][1] + table[n][k][2] + table[n][k][3]) % smod << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

