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
	
	int data[n+1];
	for(int x=1;x<=n;x++){
		cin >> data[x];
	}
	
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	
	int table[n+1][n+1][2];
	for(int x=0;x<=n;x++){
		for(int y=0;y<=n;y++) table[x][y][0] = table[x][y][1] = inf_int;
	}
	
	table[0][0][0] = table[0][0][1] = 0;
	
	for(int x=1;x<=n;x++){
		for(int y=0;y<=n/2;y++){
			if(data[x] == 0){
				table[x][y+1][0] = min(table[x-1][y][0], table[x-1][y][1]+1);
				table[x][y][1] = min(table[x-1][y][1], table[x-1][y][0]+1);
			} else {
				if(data[x]&1){
					table[x][y][1] = min(table[x-1][y][1], table[x-1][y][0]+1);
				} else {
					table[x][y+1][0] = min(table[x-1][y][0], table[x-1][y][1]+1);
				}
			}
		}
	}
	
	cout << min(table[n][n/2][0], table[n][n/2][1]) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

