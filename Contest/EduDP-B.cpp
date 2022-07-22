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

	int n, k;
	cin >> n >> k;
	
	ll data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	ll table[n];
	fill(table, table+n, inf_ll);
	
	table[0] = 0;
	for(int x=0;x<n;x++){
		for(int y=1;y<=k;y++){
			if(x+y >= n) break;
			
			table[x+y] = min(table[x+y], table[x] + abs(data[x+y]-data[x]));
		}
	}
	
	cout << table[n-1] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

