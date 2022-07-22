#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	bool table[n][2];
	fill(table[0], table[n], false);
	
	table[0][0] = table[0][1] = true;
	for(int x=0;x+1<n;x++){
		if(abs(a[x]-a[x+1]) <= k){
			table[x+1][0] |= table[x][0];
		}
		if(abs(a[x]-b[x+1]) <= k){
			table[x+1][1] |= table[x][0];
		}
		
		if(abs(b[x]-a[x+1]) <= k){
			table[x+1][0] |= table[x][1];
		}
		if(abs(b[x]-b[x+1]) <= k){
			table[x+1][1] |= table[x][1];
		}
	}
	
	cout << ((table[n-1][0] || table[n-1][1]) ? "Yes" : "No") << "\n";
    return 0;
}

