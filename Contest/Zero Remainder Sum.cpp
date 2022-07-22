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

int table[70][71][2];
short data[70][70], n, m, k;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m >> k;
	
	fill(table[0][0], table[n][71], 0);
	
	for(short x=0;x<n;x++){
		for(short y=0;y<m;y++){
			cin >> data[x][y];
		}
	}
	
	for(short x=0;x<n;x++){
		for(short y=0;y<m;y++){
			table[n-1][0][0] = max()
		}
	}
	
	cout << max(table[n-1][0][0], table[n-1][0][1]) << "\n";
    return 0;
}

