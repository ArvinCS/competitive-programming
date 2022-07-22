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
	
	int n, m;
	cin >> n >> m;
	
	int a[n], b[m];
	for(us x=0;x<n;x++) cin >> a[x];
	for(us x=0;x<m;x++) cin >> b[x];
	
	int table[n+1][m+1];
	for(int x=0;x<=n;x++){
		table[x][0] = x;
	}
	for(int x=0;x<=m;x++){
		table[0][x] = x;
	}
	
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			table[x][y] = min(table[x-1][y] + 1, min(table[x][y-1] + 1, table[x-1][y-1] + (a[x-1] != b[y-1])));
		}
	}
	
	cout << table[n][m] << "\n";
    return 0;
}

