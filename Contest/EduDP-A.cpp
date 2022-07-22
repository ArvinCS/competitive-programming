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
	
	int data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	ll table[n];
	fill(table, table+n, inf_int);
	
	table[0] = 0;
	for(int x=0;x+1<n;x++){
		table[x+1] = min(table[x+1], table[x] + abs(data[x+1]-data[x]));
		if(x+2 < n) table[x+2] = min(table[x+2], table[x] + abs(data[x+2]-data[x]));
	}
	
	cout << table[n-1] << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

