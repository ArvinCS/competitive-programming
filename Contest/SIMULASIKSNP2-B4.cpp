#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 50;

int table[maxN];

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
	
	fill(table, table+n+1, 0);
	
	int mx = 0, cnt = 0;
	for(int x=0;x<n;x++){
		table[a[x]] = 1+table[a[x]-1];
		
		if(table[a[x]] >= mx){
			if(table[a[x]] == mx){
				cnt++;
			} else {
				cnt = 1;
			}
			mx = table[a[x]];
		}
	}
	
	cout << n-mx << " " << cnt << "\n";
    return 0;
}

