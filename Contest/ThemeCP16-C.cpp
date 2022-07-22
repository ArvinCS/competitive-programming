#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
		}
		
		ll table[n];
		fill(table, table+n, 0);
		
		ll ans = 0;
		for(int x=0;x<n;x++){
			ll cnt = 0;
			
			for(int y=x+1;y<n;y++){
				if(a[x] == a[y]){
					ans += cnt;
				}
				
				cnt += table[y];
				
				if(a[x] == a[y]){
					table[y]++;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

