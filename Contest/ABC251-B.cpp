#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, w;
	cin >> n >> w;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	bool table[w+1];
	fill(table, table+w+1, false);
	
	table[0] = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			for(int z=y+1;z<n;z++){
				if(a[x]+a[y]+a[z] <= w){
					table[a[x]+a[y]+a[z]] = true;
				}
			}
			
			if(a[x]+a[y] <= w){
				table[a[x]+a[y]] = true;
			}
		}
		
		if(a[x] <= w){
			table[a[x]] = true;
		}
	}
	
	int ans = 0;
	for(int x=1;x<=w;x++){
		if(table[x]) ans++;
	}
	
	cout << ans << "\n";
    return 0;
}

