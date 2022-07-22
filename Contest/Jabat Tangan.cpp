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
	
	ll table[n+1];
	fill(table, table+n+1, 0);
	table[2] = 1;
	table[4] = 2;
	for(int x=6;x<=n;x+=2){
		int pos = x/2;
		for(int y=1;y<=pos;y++){
			int left = x-2*y, right = 2*y-2;
//			cout << y << ": " << left << " " << right << "\n";
			table[x] += max(table[left], 1ll) * max(table[right], 1ll); 
		}
	}
	
	cout << table[n] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

