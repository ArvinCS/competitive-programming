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
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int r, c;
		cin >> r >> c;
		
		int grid[r][c];
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				char tmp;
				cin >> tmp;
				
				grid[x][y] = (tmp - '0');
			}
		}
		
		int ver[r][c], hor[r][c];
		fill(ver[0], ver[r], 0);
		fill(hor[0], hor[r], 0);
		
		for(int y=0;y<c;y++){
			for(int x=r-1;x>=0;x--){
				if(grid[x][y] == 1){
					ver[x][y]++;
					if(x+1 < r && grid[x][y] == grid[x+1][y]){
						ver[x][y] += ver[x+1][y];
					}
				}
			}
		}
		
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				if(grid[x][y] == 1){
					hor[x][y]++;
					if(y-1 >= 0 && grid[x][y] == grid[x][y-1]){
						hor[x][y] += hor[x][y-1];
					}
				}
			}
		}
		
		int ans = 0;
		for(int x=0;x<r;x++){
			for(int y=0;y<c;y++){
				if(grid[x][y] == 0) continue;
				
				int length = 1;
				for(int z=y-1;z>=0;z--){
					if(grid[x][z] == 0) break;
					length++;
					
					if(x-2*length+1 >= 0 && ver[x-2*length+1][z] >= 2*length){
//						cout << "a " << x << " " << y << " -> " << x-2*length+1 << " " << z << "\n";
						ans++;
					}
					if(ver[x][z] >= 2*length){
//						cout << "b " << x << " " << y << " -> " << x+2*length-1 << " " << z << "\n";
						ans++;
					}
					
					if(length > 2 && length % 2 == 0){
						if(x-length/2+1 >= 0 && ver[x-length/2+1][z] >= length/2){
//							cout << "c " << x << " " << y << " -> " << x-length/2+1 << " " << z << "\n";
							ans++;
						}
						if(ver[x][z] >= length/2){
//							cout << "d " << x << " " << y << " -> " << x+length/2-1 << " " << z << "\n";
							ans++;
						}
					}
				}
				length = 1;
				for(int z=y+1;z<c;z++){
					if(grid[x][z] == 0) break;
					length++;
					
					if(x-2*length+1 >= 0 && ver[x-2*length+1][z] >= 2*length){
//						cout << "a " << x << " " << y << " -> " << x-2*length+1 << " " << z << "\n";
						ans++;
					}
					if(ver[x][z] >= 2*length){
//						cout << "b " << x << " " << y << " -> " << x+2*length-1 << " " << z << "\n";
						ans++;
					}
					
					if(length > 2 && length % 2 == 0){
						if(x-length/2+1 >= 0 && ver[x-length/2+1][z] >= length/2){
//							cout << "c "<< x << " " << y << " -> " << x-length/2+1 << " " << z << "\n";
							ans++;
						}
						if(ver[x][z] >= length/2){
//							cout << x << " " << y << " -> " << x+length/2-1 << " " << z << "\n";
							ans++;
						}
					}
				}
			}
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

