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
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int sz = (1<<n);
	int table[sz];
	fill(table, table+sz, 0);
	
	for(int i = 0; i<sz; ++i)
		table[i] = a[i];
	for(int i = 0;i < n; ++i) for(int mask = 0; mask < sz; ++mask){
		if(mask & (1<<i))
			table[mask] += table[mask^(1<<i)];
	}
	
	for(int x=0;x<sz;x++){
		cout << x << " -> " << table[x] << "\n";
	}
    return 0;
}
