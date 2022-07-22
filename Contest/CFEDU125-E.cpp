#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	ll table[n];
	fill(table, table+n, 0);
	
	table[0] = 1;
	for(int x=1;x<n;x++){
		for(int y=1;y<=k;y++){
			table[x] += table[x-1] * max(1ll, (x-1)*1ll*(k-y+1));
		}
	}
	
	cout << table[n-1] << "\n";
    return 0;
}

