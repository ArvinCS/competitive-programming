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
	
	us q;
	cin >> q;
	
	while(q--){
		short n;
		cin >> n;
		
		short data[n];
		for(short x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		int table[401][n+1];
		fill(table[0], table[401], inf_int);
		for(short x=0;x<=400;x++){
			table[x][0] = 0;
		}
		
		for(short x=0;x<n;x++){
			for(short t=1;t<=400;t++){
				table[t][x+1] = min(table[t-1][x+1], table[t-1][x] + abs(data[x]-t));
			}
		}		
		
		cout << table[400][n] << "\n";
	}
	
    return 0;
}

