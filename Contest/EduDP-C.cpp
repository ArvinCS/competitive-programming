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

	int n;
	cin >> n;
	
	int data[n][3];
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++) cin >> data[x][y];
	}
	
	ll table[n][3];
	fill(table[0], table[n], 0);
	
	for(int x=0;x<3;x++) table[0][x] = data[0][x];
	for(int x=1;x<n;x++){
		for(int y=0;y<3;y++){
			for(int z=0;z<3;z++){
				if(y == z) continue;
				
				table[x][y] = max(table[x][y], table[x-1][z]+data[x][y]);
			}
		}
	}
	
	ll ans = 0;
	for(int x=0;x<3;x++) ans = max(ans, table[n-1][x]);
	cout << ans << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

