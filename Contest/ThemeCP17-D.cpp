#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> a[x][y];
		}
	}
	
	ll table[n][n][n];
	fill(*table[0], *table[n], -1e18);
	
	int cur = 0;
	for(int r=0;r<n;r++){
		cur += a[0][r];
		for(int l=0;l<=r;l++){
			table[0][l][r] = cur;
			cout << 0 << " " << l << "," << r << " -> " << cur << "\n";
		}
	}
	
	for(int x=1;x<n;x++){
		ll cur = -1e18;
		for(int l=0;l<n;l++){
			cur += a[x][l];
			for(int r=l;r<n;r++){
				cur = max(cur+a[x][r], table[x-1][l][r] + a[x][l] + (l != r ? a[x][r] : 0));
				
				table[x][l][r] = max(table[x][l][r], cur);
				cout << x << " " << l << "," << r << " -> " << table[x][l][r] << "\n";
			}
		}
	}
	
	cout << table[n-1][n-1][n-1] << "\n";
    return 0;
}

