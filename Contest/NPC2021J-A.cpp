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

const short maxN = 1005;

ll table[maxN][maxN]; // plate sum

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	fill(table[0], table[maxN], 0);
	
	for(short x=0;x<maxN;x++){
		table[0][x] = 1;
		table[x][1] = 1;
	}
	
	for(short x=0;x<maxN;x++){
		for(short y=1;y<maxN;y++){
			if(x == 0 || y == 1) continue;
			
			table[x][y] = table[x][y-1];
			if(x-y >= 0){
				table[x][y] += table[x-y][y];
				if(table[x][y] >= mod) table[x][y] -= mod;
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		short n, m;
		cin >> n >> m;
		
		cout << table[n][m] << "\n";
	}
    return 0;
}

