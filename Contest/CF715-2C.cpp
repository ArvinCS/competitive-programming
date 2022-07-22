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
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	sort(data, data+n);
	
	ll table[n+1][n+1];
	fill(table[0], table[n+1], inf_ll);
	
	for(int x=0;x<n;x++){
		table[x][x] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int x=0;x<n;x++){
			int y = x+i;
			if(y >= n) break;
			table[x][y] = min(data[y] - data[x] + table[x+1][y], data[y] - data[x] + table[x][y-1]);
		}
	}
	
	cout << table[0][n-1] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

