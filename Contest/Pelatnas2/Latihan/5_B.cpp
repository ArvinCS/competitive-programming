#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 300;
const int maxN = 1e3 + 5;

ll table[maxN][2*maxA][2*maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int e;
	cin >> e;
	
	int a[n], b[n];
	for(int x=0;x<n-1;x++){
		cin >> a[x] >> b[x];
	}
	
	fill(table[0], table[n], 0);
	
	for(int x=0;x<2*maxA;x++){
		table[n-1][x] = x;
	}
	
	for(int x=n-2;x>=0;x--){
		for(int y=0;y<maxA;y++){
			for(int z=0;z<2*maxA;z++){
				int mv = max(0, z-b[x]);
				if(y+mv >= a[x]){
					if(y+z < 2*maxA){
						table[x][y+z] = max(table[x][y+z], y+table[x+1][z]);
					}
				} else {
					if(y+mv < 2*maxA){
						table[x][y+mv] = max(table[x][y+mv], y+table[x+1][z]);
					}
				}
			}
		}
		
		for(int y=0;y<maxA;y++){
			for(int z=2*maxA-2;z>=0;z--){
				table[y][z] += table[y][z+1];
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<e;x++){
		ans = max(ans, table[0][x]);
	}
	
	cout << ans << "\n";
    return 0;
}

