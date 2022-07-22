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
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll table[n][10];
	for(int k=0;k<10;k++){
		fill(table[0], table[n], 0);
		
		table[0][a[0]] = 1;
		for(int x=1;x<n;x++){
			for(int y=0;y<10;y++){
				table[x][(y+a[x])%10] += table[x-1][y];
				table[x][(y+a[x])%10] %= smod;
				table[x][(y*a[x])%10] += table[x-1][y];
				table[x][(y*a[x])%10] %= smod;
			}
		}
		
		cout << table[n-1][k] << "\n";
	}
    return 0;
}

