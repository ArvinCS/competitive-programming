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
		
		char grid[2][n];
		for(int x=0;x<2;x++){
			for(int y=0;y<n;y++){
				cin >> grid[x][y];
			}
		}
		
		int state[n];
		for(int x=0;x<n;x++){
			state[x] = 0;
			for(int y=0;y<2;y++){
				if(grid[y][x] == '*') state[x] |= (1 << y);
			}
		}
		
		int prefix[n][4], suffix[n][4];
		fill(prefix[0], prefix[n], 1e8);
		fill(suffix[0], suffix[n], 1e8);
		
		auto sp = [&](int from, int to) -> int {
			if(to == 1){
				return (from == 0 ? 0 : (from == 1 ? 1 : 2));
			} else if(to == 2){
				return (from == 0 ? 0 : (from % 2 == 0 ? 1 : 2));
			} else if(to == 3){
				return __builtin_popcount(from);
			}
		};
		auto conv = [&](int a, int b) -> int {
			if(b == 0){
				if(a == 0) return 0;
				else return 1e8;
			} else if(b == 1){
				if(a == 0){
					return __builtin_popcount(b);
				} else if(a == 1){
					return 0;
				} else if(a == 2){
					return 1;
				} else if(a == 3){
					return 1;
				}
			} else if(b == 2){
				if(a == 0){
					return __builtin_popcount(b);
				} else if(a == 1){
					return 1;
				} else if(a == 2){
					return 0;
				} else if(a == 3){
					return 1;
				}
			} else if(b == 3){
				if(a == 0){
					return __builtin_popcount(b);
				} else if(a == 1){
					return 0;
				} else if(a == 2){
					return 0;
				} else if(a == 3){
					return 0;
				}
			}
		};
		
		for(int x=0;x<4;x++){
			prefix[0][x] = conv(state[0], x);
			suffix[n-1][x] = conv(state[n-1], x); 
		}
		
		for(int x=1;x<n;x++){
			for(int y=0;y<4;y++){
				for(int z=0;z<4;z++){
					if(prefix[x-1][z] == 1e8) continue;
					if((z|state[x]) != 0 && y == 0) continue;
					
					prefix[x][y] = min(prefix[x][y], conv(state[x], y)+prefix[x-1][z]+sp(z, state[x]|y));
					cout << x << " " << y << " " << z << " -> " << conv(state[x], y) << " " << prefix[x-1][z]<<"+"<<sp(z, state[x]|y) << "\n";
				}
			}
		}
		for(int x=n-2;x>=0;x--){
			for(int y=0;y<4;y++){
				for(int z=0;z<4;z++){
					if(suffix[x+1][z] == 1e8) continue;
					if((z|state[x]) != 0 && y == 0) continue;
					
					suffix[x][y] = min(suffix[x][y], conv(state[x], y)+suffix[x+1][z]+sp(z, state[x]|y));
				}
			}
		}
		
		int ans = 1e9;
		for(int x=0;x<n;x++){
			if(state[x] == 0) continue;
			for(int y=1;y<3;y++){
				for(int l=0;l<4;l++){
					for(int r=0;r<4;r++){
						if(x > 0 && prefix[x-1][l] == 1e8) continue;
						if(x+1 < n && suffix[x+1][r] == 1e8) continue;
						
						ans = min(ans, conv(state[x], y)+(x>0?prefix[x-1][l]:0)+(x+1<n?suffix[x+1][r]:0)+sp(l, state[x]|y)+sp(r, state[x]|y));
						cout << x << " " << l << " " << r << " " << y << " -> " << ans << "\n";
					}
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

