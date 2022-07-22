#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int r, n;
	ll m;
	cin >> r >> n >> m;
	
	if(n == 1){
		cout << (1%m) << "\n";
		return 0;
	}
	
	ll ways[n+1][n+1];
	fill(ways[0], ways[n+1], 0);
	
	ways[1][0] = 1;
	for(int x=1;x<n;x++){
		for(int y=0;y<=x;y++){
			if(y+1 <= n){
//				if(x == 3) cout << x+1 << "," << y+1 << " " <<  ways[x][y] * (x-y+1)/2 % m << " -\n";
				ways[x+1][y+1] += ways[x][y] * (x-y+1)/2 % m;
				if(ways[x+1][y+1] >= m) ways[x+1][y+1] -= m;
			}
			if(y > 0){
//				if(x == 3) cout << x+1 << "," << y-1 << " " <<  ways[x][y] * y % m << " =\n";
				ways[x+1][y-1] += ways[x][y] * y % m;
				if(ways[x+1][y-1] >= m) ways[x+1][y-1] -= m;
			}
		}
	}
	
	ll table[n+1][n+1][2];
	fill(*table[0], *table[n+1], 0);
	
	// 0 if we put add R to a vertex with no children
	// 1 if we put add R to a vertex with 1 children
	for(int y=0;y<=n-r;y++){
		if(y+1 <= n){
			table[n-r+1][y+1][0] += ways[n-r][y] * (n-r-y+1)/2 % m;
			if(table[n-r+1][y+1][0] >= m) table[n-r+1][y+1][0] -= m;
		}
		if(y > 0){
			table[n-r+1][y-1][1] += ways[n-r][y] * y % m;
			if(table[n-r+1][y-1][1] >= m) table[n-r+1][y-1][1] -= m;
		}
	}
	
	for(int x=n-r+1;x<n;x++){
		for(int y=0;y<=x;y++){
			for(int i=0;i<2;i++){
				if(y+1 <= n){
					table[x+1][y+1][i] += table[x][y][i] * max(0, (x-y+1)/2 - 1) % m;
					if(table[x+1][y+1][i] >= m) table[x+1][y+1][i] -= m;
				}
				if(y > 0){
					table[x+1][y-1][i] += table[x][y][i] * y % m;
					if(table[x+1][y-1][i] >= m) table[x+1][y-1][i] -= m;
				}
			}
		}
	}
	
	ll ans = 0;
	for(int y=0;y<=n;y++){
		ans += table[n][y][0];
		if(ans >= m) ans -= m;
		
		ans += table[n][y][1];
		if(ans >= m) ans -= m;
	}
	
	cout << ans << "\n";
    return 0;
}

