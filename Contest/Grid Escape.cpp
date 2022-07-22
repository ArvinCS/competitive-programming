#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us r, c, n;
	cin >> r >> c >> n;
	
	bool trap[r+1][c+1];
	fill(trap[0], trap[r+1], false);
	
	while(n--){
		us tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		trap[tmp1][tmp2] = true;	
	}
	
	ui ways[r+1][c+1];
	fill(ways[0], ways[r+1], 0);
	
	// x vertical | y horizontal
	ways[1][1] = 1;
	for(us x=1;x<=r;x++){
		ways[x][1] = 1;
	}
	for(us y=1;y<=c;y++){
		ways[1][y] = 1;
	}
	for(us x=1;x<=r;x++){
		for(us y=1;y<=c;y++){
			if((x == 1 && y > 1) || y == 1) continue;
			if(trap[x][y]) continue;
			ways[x][y] = ways[x-1][y] + ways[x][y-1];
			ways[x][y] %= mod;
		}
	}
	
	cout << ways[r][c] << "\n";
    return 0;
}

